#include "double_linked_list.h"

Data::Data(const std::vector<std::pair<double, double>>& data) : pulseData(data) {
    calculateMaxMin();
}

void Data::calculateMaxMin() {
    maxValue = -1e9;
    minValue = 1e9;
    for (const auto& p : pulseData) {
        if (p.second > maxValue) maxValue = p.second;
        if (p.second < minValue) minValue = p.second;
    }
    if (!pulseData.empty()) {
        duration = pulseData.back().first - pulseData.front().first;
    }
}

void Data::normalize(double globalMax) {
    if (globalMax > 0) {
        for (auto& p : pulseData) {
            p.second /= globalMax;
        }
        calculateMaxMin();
    }
}

DoubleLinkedList::DoubleLinkedList() : Head(nullptr), Tail(nullptr), countNodes(0) {}

DoubleLinkedList::~DoubleLinkedList() {
    while (Head) {
        Node* temp = Head;
        Head = Head->next;
        delete temp;
    }
    Tail = nullptr;
    countNodes = 0;
}

void DoubleLinkedList::push_back(const Data* d) {
    Data* newData = new Data(*d);
    Node* newNode = new Node(newData);

    if (!Head) {
        Head = Tail = newNode;
    }
    else {
        Tail->next = newNode;
        newNode->prev = Tail;
        Tail = newNode;
    }
    countNodes++;
}

void DoubleLinkedList::push_front(const Data* d) {
    Data* newData = new Data(*d);
    Node* newNode = new Node(newData);

    if (!Head) {
        Head = Tail = newNode;
    }
    else {
        newNode->next = Head;
        Head->prev = newNode;
        Head = newNode;
    }
    countNodes++;
}

std::vector<std::pair<double, double>> DoubleLinkedList::get_Node(int num_node) const {
    if (num_node < 0 || num_node >= countNodes) {
        if (Tail) return Tail->data->pulseData;
        return {};
    }

    Node* current = Head;
    for (int i = 0; i < num_node && current; i++) {
        current = current->next;
    }

    if (current) return current->data->pulseData;
    return {};
}

int DoubleLinkedList::getCountNodes() const {
    return countNodes;
}

void DoubleLinkedList::pop_front() {
    if (!Head) return;

    Node* temp = Head;
    Head = Head->next;
    if (Head) Head->prev = nullptr;
    else Tail = nullptr;

    delete temp;
    countNodes--;
}

void DoubleLinkedList::pop_back() {
    if (!Tail) return;

    Node* temp = Tail;
    Tail = Tail->prev;
    if (Tail) Tail->next = nullptr;
    else Head = nullptr;

    delete temp;
    countNodes--;
}

void DoubleLinkedList::insert(const Data* d, int num_node) {
    if (num_node <= 0) {
        push_front(d);
        return;
    }
    if (num_node >= countNodes) {
        push_back(d);
        return;
    }

    Node* current = Head;
    for (int i = 0; i < num_node && current; i++) {
        current = current->next;
    }

    Data* newData = new Data(*d);
    Node* newNode = new Node(newData);

    newNode->prev = current->prev;
    newNode->next = current;
    if (current->prev) current->prev->next = newNode;
    current->prev = newNode;

    countNodes++;
}

void DoubleLinkedList::printFront() const {
    // Функция оставлена пустой по требованию (не используем cout в cpp)
    // Вывод осуществляется только в main.cpp
}