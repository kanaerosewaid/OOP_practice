#include <iostream>
#include <vector>
#include "BaseClass.h"
#include "DerivedClass1.h"
#include "DerivedClass2.h"
#include "Menu.h"

int main() {
    const int SIZE = 5;
    std::vector<BaseClass*> objects(SIZE);

    // Заповнення масиву
    for (int i = 0; i < SIZE; ++i) {
        int choice = showMenu();
        if (choice == 1) {
            objects[i] = new DerivedClass1();
        } else if (choice == 2) {
            objects[i] = new DerivedClass2();
        } else {
            std::cout << "Invalid choice. Defaulting to DerivedClass1.\n";
            objects[i] = new DerivedClass1();
        }
    }

    // Виведення даних об'єктів
    std::cout << "\nObject information:\n";
    for (int i = 0; i < SIZE; ++i) {
        objects[i]->display();
    }

    // Виклик віртуального методу
    std::cout << "\nCalling virtual methods:\n";
    for (int i = 0; i < SIZE; ++i) {
        objects[i]->display();
    }

    // Видалення об'єктів
    for (int i = 0; i < SIZE; ++i) {
        delete objects[i];
    }

    return 0;
}
