#include <iostream>
#include "Student.h"

int main() {
    Student student1(1, "Іванов", "Іван", "Іванович", "Київ, вул. Примерна 1", "0991234567", "Філологічний", 1, "ФІ-11");
    Student student2(2, "Петров", "Петро", "Петрович", "Львів, вул. Тестова 3", "0977654321", "Інженерний", 2, "ІН-21");

    student1.display();
    student2.display();

    return 0;
}
