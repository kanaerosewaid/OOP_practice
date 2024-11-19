#ifndef HOTEL_H
#define HOTEL_H

#include <QString>

class Hotel {
public:
    Hotel();
    Hotel(QString name, double price, int rooms);
    ~Hotel();

    QString getName() const { return name; }
    double getPrice() const { return price; }
    int getRooms() const { return rooms; }

    QString toString();
private:
    QString name;
    double price;
    int rooms;
};


#endif // HOTEL_H
