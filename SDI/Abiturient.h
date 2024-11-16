#ifndef ABITURIENT_H
#define ABITURIENT_H

#include <string>

class Abiturient {
private:
    int id;
    std::string lastName;
    std::string firstName;
    std::string middleName;
    std::string address;
    std::string phone;
    int yearOfZNO;
    std::string znoCertificateNumber;
    std::string pinCode;

public:
    // Конструктор за замовчуванням
    Abiturient();

    // Параметризований конструктор
    Abiturient(int id, const std::string& lastName, const std::string& firstName,
               const std::string& middleName, const std::string& address,
               const std::string& phone, int yearOfZNO,
               const std::string& znoCertificateNumber, const std::string& pinCode);

    // Конструктор копіювання
    Abiturient(const Abiturient& other);

    // Деструктор
    ~Abiturient();

    // Методи для доступу до полів
    void displayInfo() const;

    friend std::istream& operator>>(std::istream& in, Abiturient& obj);
    friend std::ostream& operator<<(std::ostream& out, const Abiturient& obj);


};

#endif // ABITURIENT_H
