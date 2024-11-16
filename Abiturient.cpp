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
}
