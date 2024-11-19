#include "hotel.h"

Hotel::Hotel() = default;

Hotel::~Hotel() = default;

Hotel::Hotel(QString name, double price, int rooms) {
    this->name = name;
    this->price = price;
    this->rooms = rooms;
}

QString Hotel::toString() {
    return QString("%1 %2 %3").arg(name).arg(price).arg(rooms);
}
