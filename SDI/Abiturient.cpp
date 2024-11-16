#include "Abiturient.h"
#include <iostream>

// Конструктор за замовчуванням
Abiturient::Abiturient() : id(0), yearOfZNO(0) {}

// Параметризований конструктор
Abiturient::Abiturient(int id, const std::string& lastName, const std::string& firstName,
                       const std::string& middleName, const std::string& address,
                       const std::string& phone, int yearOfZNO,
                       const std::string& znoCertificateNumber, const std::string& pinCode)
    : id(id), lastName(lastName), firstName(firstName), middleName(middleName),
      address(address), phone(phone), yearOfZNO(yearOfZNO),
      znoCertificateNumber(znoCertificateNumber), pinCode(pinCode) {}

// Конструктор копіювання
Abiturient::Abiturient(const Abiturient& other) 
    : id(other.id), lastName(other.lastName), firstName(other.firstName), 
      middleName(other.middleName), address(other.address), phone(other.phone), 
      yearOfZNO(other.yearOfZNO), znoCertificateNumber(other.znoCertificateNumber), 
      pinCode(other.pinCode) {}

// Деструктор
Abiturient::~Abiturient() {}

// Метод для відображення інформації
void Abiturient::displayInfo() const {
    std::cout << "ID: " << id << "\n"
              << "Прізвище: " << lastName << "\n"
              << "Ім'я: " << firstName << "\n"
              << "По батькові: " << middleName << "\n"
              << "Адреса: " << address << "\n"
              << "Телефон: " << phone << "\n"
              << "Рік здачі ЗНО: " << yearOfZNO << "\n"
              << "Номер сертифікату ЗНО: " << znoCertificateNumber << "\n"
              << "Пін-код: " << pinCode << "\n";

              std::istream& operator>>(std::istream& in, Abiturient& obj) {
    std::cout << "Введіть ID: ";
    in >> obj.id;
    std::cout << "Введіть прізвище: ";
    in >> obj.lastName;
    std::cout << "Введіть ім'я: ";
    in >> obj.firstName;
    std::cout << "Введіть по батькові: ";
    in >> obj.middleName;
    std::cout << "Введіть адресу: ";
    in.ignore(); // Для коректного читання рядка
    std::getline(in, obj.address);
    std::cout << "Введіть телефон: ";
    in >> obj.phone;
    std::cout << "Введіть рік здачі ЗНО: ";
    in >> obj.yearOfZNO;
    std::cout << "Введіть номер сертифікату ЗНО: ";
    in >> obj.znoCertificateNumber;
    std::cout << "Введіть пін-код сертифікату: ";
    in >> obj.pinCode;
    return in;
}
std::ostream& operator<<(std::ostream& out, const Abiturient& obj) {
    out << "ID: " << obj.id << "\n"
        << "Прізвище: " << obj.lastName << "\n"
        << "Ім'я: " << obj.firstName << "\n"
        << "По батькові: " << obj.middleName << "\n"
        << "Адреса: " << obj.address << "\n"
        << "Телефон: " << obj.phone << "\n"
        << "Рік здачі ЗНО: " << obj.yearOfZNO << "\n"
        << "Номер сертифікату ЗНО: " << obj.znoCertificateNumber << "\n"
        << "Пін-код: " << obj.pinCode << "\n";
    return out;
}


}
