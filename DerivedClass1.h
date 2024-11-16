#ifndef DERIVEDCLASS1_H
#define DERIVEDCLASS1_H

#include "BaseClass.h"

class DerivedClass1 : public BaseClass {
public:
    void virtualMethod() override {
        std::cout << "DerivedClass1 method called.\n";
    }
};

#endif // DERIVEDCLASS1_H
