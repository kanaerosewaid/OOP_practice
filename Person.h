#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    int id;
    std::string lastName;
    std::string firstName;
    std::string middleName;
    std::string address;
    std::string phone;

public:
    Person(int id, std::string lastName, std::string firstName, std::string middleName,
           std::string address, std::string phone);
    virtual void display() const;
};

#endif
