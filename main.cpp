#include <iostream>
#include "Abiturient.h"

int main() {
    Abiturient object1, object2, object3;
    std::cin >> object1 >> object2 >> object3;

    object1.displayInfo();
    object2.displayInfo();
    object3.displayInfo();

    return 0;
}
