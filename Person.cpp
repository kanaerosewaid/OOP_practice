#include "Person.h"
#include <iostream>

Person::Person(int id, std::string lastName, std::string firstName, std::string middleName,
               std::string address, std::string phone)
    : id(id), lastName(lastName), firstName(firstName), middleName(middleName),
      address(address), phone(phone) {}

void Person::display() const {
    std::cout << "ID: " << id << "\n"
              << "Прізвище: " << lastName << "\n"
              << "Ім'я: " << firstName << "\n"
              << "По батькові: " << middleName << "\n"
              << "Адреса: " << address << "\n"
              << "Телефон: " << phone << "\n";
}
