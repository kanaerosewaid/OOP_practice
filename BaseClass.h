// BaseClass.h
#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>
#include <string>

class BaseClass {
public:
    virtual void display() const = 0; // Суто віртуальний метод
    virtual ~BaseClass() = default;  // Віртуальний деструктор
};

#endif // BASECLASS_H
