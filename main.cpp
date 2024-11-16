#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include "BaseClass.h"
#include "DerivedClass1.h"
#include "DerivedClass2.h"

void fillOddVector(std::vector<int>& vec) {
    for (int i = 0; i < 10; ++i) {
        vec.push_back(1 + i * 4); // Непарні непослідовні числа
    }
}

void fillEvenVector(std::vector<int>& vec) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(10, 50);

    for (int i = 0; i < 10; ++i) {
        int number;
        do {
            number = dist(gen);
        } while (number % 2 != 0); // Генеруємо лише парні
        vec.push_back(number);
    }
}

template <typename T>
void printVector(const std::vector<T>& vec, const std::string& label) {
    std::cout << label << ": ";
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int showMenu() {
    int choice;
    std::cout << "Select class to create:\n";
    std::cout << "1. DerivedClass1\n";
    std::cout << "2. DerivedClass2\n";
    std::cout << "Enter choice (1 or 2): ";
    std::cin >> choice;
    return choice;
}

int main() {
    // Завдання 2: Заповнення векторів
    std::vector<int> oddVec, evenVec;
    fillOddVector(oddVec);
    fillEvenVector(evenVec);

    // Сортування векторів
    std::sort(oddVec.begin(), oddVec.end());
    std::sort(evenVec.begin(), evenVec.end());

    // Завдання 3: Об'єднання векторів
    std::vector<int> mergedVec(oddVec.size() + evenVec.size());
    std::merge(oddVec.begin(), oddVec.end(), evenVec.begin(), evenVec.end(), mergedVec.begin());

    // Виведення векторів
    printVector(oddVec, "Odd Vector");
    printVector(evenVec, "Even Vector");
    printVector(mergedVec, "Merged Vector");

    // Завдання 4: Робота з похідними класами
    std::vector<BaseClass*> baseVector;
    for (int i = 0; i < 5; ++i) {
        int choice = showMenu();
        if (choice == 1) {
            baseVector.push_back(new DerivedClass1());
        } else if (choice == 2) {
            baseVector.push_back(new DerivedClass2());
        }
    }

    // Завдання 5: Робота з векторами похідних класів
    std::vector<BaseClass*> vectorCopy = baseVector;

    // Видалення об'єктів першого підкласу з першого вектора
    baseVector.erase(
        std::remove_if(baseVector.begin(), baseVector.end(), [](BaseClass* obj) {
            return dynamic_cast<DerivedClass1*>(obj) != nullptr;
        }),
        baseVector.end()
    );

    // Видалення об'єктів другого підкласу з другого вектора
    vectorCopy.erase(
        std::remove_if(vectorCopy.begin(), vectorCopy.end(), [](BaseClass* obj) {
            return dynamic_cast<DerivedClass2*>(obj) != nullptr;
        }),
        vectorCopy.end()
    );

    // Виведення результатів
    std::cout << "\nBase Vector after removing DerivedClass1 objects:\n";
    for (const auto& obj : baseVector) {
        obj->virtualMethod();
    }

    std::cout << "\nVector Copy after removing DerivedClass2 objects:\n";
    for (const auto& obj : vectorCopy) {
        obj->virtualMethod();
    }

    // Звільнення пам'яті
    for (auto& obj : baseVector) {
        delete obj;
    }
    for (auto& obj : vectorCopy) {
        delete obj;
    }

    return 0;
}
