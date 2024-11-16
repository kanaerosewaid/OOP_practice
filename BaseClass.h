#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>

class BaseClass {
public:
    virtual ~BaseClass() {}
    virtual void virtualMethod() = 0; // Суто віртуальний метод
};

#endif // BASECLASS_H
