#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    int id;
    std::string lastName;
    std::string firstName;
    std::string middleName;
    std::string address;
    std::string phone;
    std::string faculty;
    int course;
    std::string group;

public:
    Student(int id, std::string lastName, std::string firstName, std::string middleName,
            std::string address, std::string phone, std::string faculty, int course, std::string group);
    void display() const;
};

#endif