#include <iostream>
#include <list>
#include <map>
#include <algorithm>
#include <random>
#include "BaseClass.h"
#include "DerivedClass1.h"
#include "DerivedClass2.h"

// Функція для заповнення списку непарними числами
void fillOddList(std::list<int>& lst) {
    for (int i = 0; i < 10; ++i) {
        lst.push_back(1 + i * 4); // Непарні непослідовні числа
    }
}

// Функція для заповнення списку парними числами
void fillEvenList(std::list<int>& lst) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(10, 50);

    for (int i = 0; i < 10; ++i) {
        int number;
        do {
            number = dist(gen);
        } while (number % 2 != 0); // Генеруємо лише парні
        lst.push_back(number);
    }
}

// Функція для виведення елементів списку
template <typename T>
void printList(const std::list<T>& lst, const std::string& label) {
    std::cout << label << ": ";
    for (const auto& val : lst) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

// Меню для вибору класу
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
    // Завдання 2: Створення та заповнення списків
    std::list<int> oddList, evenList;
    fillOddList(oddList);
    fillEvenList(evenList);

    // Завдання 3: Об'єднання списків
    oddList.sort();  // Сортуємо списки
    evenList.sort();
    std::list<int> mergedList;
    std::merge(oddList.begin(), oddList.end(), evenList.begin(), evenList.end(), std::back_inserter(mergedList));

    // Завдання 4: Виведення списків
    printList(oddList, "Odd List");
    printList(evenList, "Even List");
    printList(mergedList, "Merged List");

    // Завдання 5: Заповнення контейнера std::map
    std::map<int, BaseClass*> baseMap;
    int id = 1;

    // Меню для додавання об'єктів у map
    while (true) {
        int choice = showMenu();
        if (choice == 1) {
            baseMap[id++] = new DerivedClass1();
        } else if (choice == 2) {
            baseMap[id++] = new DerivedClass2();
        } else {
            break;
        }
    }

    // Завдання 7: Виведення об'єктів з контейнера std::map за id
    while (true) {
        std::cout << "Enter ID to display object (or 0 to exit): ";
        int searchId;
        std::cin >> searchId;

        if (searchId == 0) {
            break;
        }

        auto it = baseMap.find(searchId);
        if (it != baseMap.end()) {
            std::cout << "Displaying object with ID " << searchId << ": ";
            it->second->virtualMethod();
        } else {
            std::cout << "Object with ID " << searchId << " not found.\n";
        }
    }

    // Звільнення пам'яті
    for (auto& pair : baseMap) {
        delete pair.second;
    }

    return 0;
}
