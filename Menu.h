#include <iostream>
#include <string>

int showMenu() {
    int choice;
    std::cout << "Select class to create:\n";
    std::cout << "1. DerivedClass1\n";
    std::cout << "2. DerivedClass2\n";
    std::cout << "Enter choice (1 or 2): ";
    std::cin >> choice;
    return choice;
}