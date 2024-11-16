#include <iostream>
#include "Vector.h"
#include "BaseClass.h"
#include "DerivedClass1.h"
#include "DerivedClass2.h"

int main() {
    // Перевірка роботи з вбудованими типами
    Vector<int> intVector;
    intVector.push_back(1);
    intVector.push_back(2);
    intVector.push_back(3);

    std::cout << "intVector: ";
    for (int i = 0; i < intVector.getSize(); ++i) {
        std::cout << intVector[i] << " ";
    }
    std::cout << "\n";

    // Перевірка роботи з базовим і похідними класами
    Vector<BaseClass*> objectVector;

    DerivedClass1 obj1;
    DerivedClass1 obj2;
    DerivedClass2 obj3;
    DerivedClass2 obj4;

    objectVector.push_back(&obj1);
    objectVector.push_back(&obj2);
    objectVector.push_back(&obj3);
    objectVector.push_back(&obj4);

    std::cout << "Calling virtual method on each object:\n";
    for (int i = 0; i < objectVector.getSize(); ++i) {
        objectVector[i]->virtualMethod();
    }

    return 0;
}
