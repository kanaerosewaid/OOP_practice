#ifndef DERIVEDCLASS2_H
#define DERIVEDCLASS2_H

#include "BaseClass.h"

class DerivedClass2 : public BaseClass {
public:
    void virtualMethod() override {
        std::cout << "DerivedClass2 method called.\n";
    }
};

#endif // DERIVEDCLASS2_H
