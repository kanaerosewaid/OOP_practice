#ifndef DOMIVKA_H
#define DOMIVKA_H

#include <QString>

class Domivka {
public:
    Domivka();
    Domivka(QString name, double price, int guests);
    ~Domivka();

    QString getName() const { return name; }
    double getPrice() const { return price; }
    int getGuests() const { return guests; }

    QString toString();
private:
    QString name;
    double price;
    int guests;
};


#endif // DOMIVKA_H
