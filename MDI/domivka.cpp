#include "domivka.h"

              Domivka::Domivka() = default;

Domivka::~Domivka() = default;

Domivka::Domivka(QString name, double price, int guests) {
    this -> name = name;
    this -> price = price;
    this -> guests = guests;
}

QString Domivka::toString() {
    return QString("%1 %2 %3 ")
    .arg(name)
        .arg(price)
        .arg(guests);
}
