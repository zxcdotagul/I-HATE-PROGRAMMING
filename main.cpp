#include "sorts.h"
#include "HW1.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <chrono>
#include <clocale>

using namespace std;
bool compAscending(int a, int b) {
    return a < b;
}

// Структура для хранения параметров программы
struct ProgramArgs {
    int maxTime = 1000;      // максимальное время в мс
    int minSize = 10;       // минимальный размер массива (увеличил для скорости)
    int maxSize = 5000000;     // максимальный размер массива (уменьшил для скорости)
    int stepSize = 50000;     // шаг изменения размера (увеличил для скорости)
    string outputFile = "results.txt";
};

// Парсинг аргументов командной строки
ProgramArgs parseArgs(int argc, char* argv[]) {
    ProgramArgs args;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--max_time") == 0 && i + 1 < argc) {
            args.maxTime = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "--min_size") == 0 && i + 1 < argc) {
            args.minSize = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "--max_size") == 0 && i + 1 < argc) {
            args.maxSize = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "--step_size") == 0 && i + 1 < argc) {
            args.stepSize = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "--output") == 0 && i + 1 < argc) {
            args.outputFile = argv[++i];
        }
    }

    return args;
}

// Быстрое измерение времени выполнения сортировки
double measureSortTime(void (*sortFunc)(int*, int, bool (*)(int, int)),
    int* arr, int size, bool (*comp)(int, int)) {
    // Создаём копию массива
    vector<int> tempArr(arr, arr + size);

    auto start = chrono::high_resolution_clock::now();
    sortFunc(tempArr.data(), size, comp);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> elapsed = end - start;
    return elapsed.count();
}

// Проверка, отсортирован ли массив
bool isSorted(int* arr, int size, bool (*comp)(int, int)) {
    for (int i = 1; i < size; i++) {
        if (!comp(arr[i - 1], arr[i])) {
            return false;
        }
    }
    return true;
}

// Тестирование одной сортировки (оптимизированная версия)
void testSort(const string& sortName,
    void (*sortFunc)(int*, int, bool (*)(int, int)),
    const ProgramArgs& args,
    bool (*comp)(int, int)) {

    string result;
    result = "\n=== " + sortName + " ===\n";
    result += "Размер\tВремя(мс)\tСтатус\n";
    writeStringToFile(args.outputFile, result);

    for (int size = args.minSize; size <= args.maxSize; size += args.stepSize) {
        // Создаём исходный массив
        vector<int> originalArr(size);
        randomFillArr(originalArr.data(), size, -1000, 1000);

        // Измеряем время сортировки
        double timeMs = measureSortTime(sortFunc, originalArr.data(), size, comp);

        // Проверяем корректность
        bool correct = true;
        if (size <= 10000) {
            vector<int> testArr = originalArr;
            sortFunc(testArr.data(), size, comp);
            correct = isSorted(testArr.data(), size, comp);
        }

        // Записываем результат
        if (timeMs <= args.maxTime) {
            result = convertIntToString(size) + "\t" +
                convertDoubleToString(timeMs) + "\t\t" +
                (correct ? "OK" : "FAIL") + "\n";
            cout << "  " << sortName << " size=" << size
                << " time=" << timeMs << "ms" << endl;
        }
        else {
            result = convertIntToString(size) + "\t---\t\tTIMEOUT\n";
            cout << "  " << sortName << " size=" << size
                << " TIMEOUT (> " << args.maxTime << "ms)" << endl;
            // При превышении времени прекращаем тестирование этого алгоритма
            writeStringToFile(args.outputFile, result);
            break;
        }

        writeStringToFile(args.outputFile, result);
    }
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    auto programStart = chrono::high_resolution_clock::now();

    // Парсим аргументы командной строки
    ProgramArgs args = parseArgs(argc, argv);

    // Выводим параметры
    cout << "========================================" << endl;
    cout << "  ТЕСТИРОВАНИЕ АЛГОРИТМОВ СОРТИРОВКИ" << endl;
    cout << "========================================" << endl;
    cout << "Параметры:" << endl;
    cout << "  Макс. время: " << args.maxTime << " мс" << endl;
    cout << "  Мин. размер: " << args.minSize << endl;
    cout << "  Макс. размер: " << args.maxSize << endl;
    cout << "  Шаг: " << args.stepSize << endl;
    cout << "  Выходной файл: " << args.outputFile << endl;
    cout << endl;

    // Очищаем файл результатов
    string header = "РЕЗУЛЬТАТЫ ТЕСТИРОВАНИЯ СОРТИРОВОК\n";
    header += "========================================\n";
    header += "Параметры: max_time=" + convertIntToString(args.maxTime) +
        "ms, min_size=" + convertIntToString(args.minSize) +
        ", max_size=" + convertIntToString(args.maxSize) +
        ", step=" + convertIntToString(args.stepSize) + "\n\n";
    writeStringToFile(args.outputFile, header);

    // Массив сортировок (только быстрые алгоритмы для выполнения < 5 секунд)
    struct SortTest {
        const char* name;
        void (*func)(int*, int, bool (*)(int, int));
    };

    // Выбираем только быстрые сортировки, исключаем медленные
    SortTest sorts[] = {
        {"Quick Sort", quickSort},      // O(n log n)
        {"Merge Sort", mergeSort},      // O(n log n)
        {"Shell Sort", sortShell},      // O(n log n)
        {"Count Sort", countSort}       // O(n + k)
        // Bubble, Selection, Insertion исключены - слишком медленные
    };

    // Тестируем каждую сортировку
    for (const auto& sort : sorts) {
        cout << "Тестирование " << sort.name << "..." << endl;
        testSort(sort.name, sort.func, args, compAscending);
        cout << "  Готово!" << endl;
    }

    auto programEnd = chrono::high_resolution_clock::now();
    chrono::duration<double> totalTime = programEnd - programStart;

    cout << "\n========================================" << endl;
    cout << "  ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << endl;
    cout << "  Общее время: " << totalTime.count() << " секунд" << endl;
    cout << "  Результаты сохранены в " << args.outputFile << endl;
    cout << "========================================" << endl;

    return 0;
}