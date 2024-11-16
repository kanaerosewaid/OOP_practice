#include <iostream>
#include "Abiturient.h"

int main() {
    Abiturient object1, object2, object3;
    std::cin >> object1 >> object2 >> object3;

    object1.displayInfo();
    object2.displayInfo();
    object3.displayInfo();

    std::cout << object1 << std::endl << object2 << std::endl << object3 << std::endl;


    return 0;
}
