#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <vector>
#include <utility>
#include <iostream>

struct Data {
    std::vector<std::pair<double, double>> pulseData; // точки импульса (время, значение)
    double maxValue; // максимальное значение импульса для нормализации
    double minValue; // минимальное значение
    double duration; // длительность импульса

    Data() : maxValue(0), minValue(0), duration(0) {}
    Data(const std::vector<std::pair<double, double>>& data);

    void calculateMaxMin();
    void normalize(double globalMax);
};

struct Node {
    Data* data;
    Node* prev;
    Node* next;

    Node(Data* d = nullptr) : data(d), prev(nullptr), next(nullptr) {}
    ~Node() { delete data; }
};

class DoubleLinkedList {
private:
    Node* Head;
    Node* Tail;
    int countNodes;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    void push_back(const Data* d);
    void push_front(const Data* d);
    std::vector<std::pair<double, double>> get_Node(int num_node) const;
    int getCountNodes() const;
    void pop_front();
    void pop_back();
    void insert(const Data* d, int num_node);
    void printFront() const;

    Node* getHead() const { return Head; }
    Node* getTail() const { return Tail; }
};

#endif
