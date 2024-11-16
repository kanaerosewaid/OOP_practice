// DerivedClass2.h
#ifndef DERIVEDCLASS2_H
#define DERIVEDCLASS2_H

#include "BaseClass.h"

class DerivedClass2 : public BaseClass {
public:
    void display() const override {
        std::cout << "This is DerivedClass2." << std::endl;
    }
};

#endif // DERIVEDCLASS2_H