#include "Student.h"
#include <iostream>

Student::Student(int id, std::string lastName, std::string firstName, std::string middleName,
                 std::string address, std::string phone, std::string faculty, int course, std::string group)
    : Person(id, lastName, firstName, middleName, address, phone), faculty(faculty), course(course), group(group) {}

void Student::display() const {
    Person::display();
    std::cout << "Факультет: " << faculty << "\n"
              << "Курс: " << course << "\n"
              << "Група: " << group << "\n";
}
