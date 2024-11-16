#include "Student.h"
#include <iostream>

Student::Student(int id, std::string lastName, std::string firstName, std::string middleName,
                 std::string address, std::string phone, std::string faculty, int course, std::string group)
    : id(id), lastName(lastName), firstName(firstName), middleName(middleName),
      address(address), phone(phone), faculty(faculty), course(course), group(group) {}

void Student::display() const {
    std::cout << "ID: " << id << "\n"
              << "Прізвище: " << lastName << "\n"
              << "Ім'я: " << firstName << "\n"
              << "По батькові: " << middleName << "\n"
              << "Адреса: " << address << "\n"
              << "Телефон: " << phone << "\n"
              << "Факультет: " << faculty << "\n"
              << "Курс: " << course << "\n"
              << "Група: " << group << "\n";
}
