#include "sqlitedbmanager.h"

SqliteDBManager::SqliteDBManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    if (!db.open()) {
        qDebug() << "Не вдалося відкрити базу даних:" << db.lastError().text();
    } else {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS Domivka ("
                   "name TEXT, "
                   "price REAL, "
                   "guests INTEGER)");

        query.exec("CREATE TABLE IF NOT EXISTS Hotel ("
                   "name TEXT, "
                   "price REAL, "
                   "rooms INTEGER)");
    }
}


SqliteDBManager::~SqliteDBManager() {
    db.close();
}

bool SqliteDBManager::addDomivka(const Domivka& domivka) {
    QSqlQuery query;
    query.prepare("INSERT INTO Domivka (name, price, guests) VALUES (?, ?, ?)");
    query.bindValue(0, domivka.getName());
    query.bindValue(1, domivka.getPrice());
    query.bindValue(2, domivka.getGuests());

    if (!query.exec()) {
        qDebug() << "Помилка додавання Domivka:" << query.lastError().text();
        return false;
    }
    return true;
}

bool SqliteDBManager::addHotel(const Hotel& hotel) {
    QSqlQuery query;
    query.prepare("INSERT INTO Hotel (name, price, rooms) VALUES (?, ?, ?)");
    query.bindValue(0, hotel.getName());
    query.bindValue(1, hotel.getPrice());
    query.bindValue(2, hotel.getRooms());

    if (!query.exec()) {
        qDebug() << "Помилка додавання Hotel:" << query.lastError().text();
        return false;
    }
    return true;
}


QList<Domivka*> SqliteDBManager::loadDomivkaData() {
    QList<Domivka*> domivkas;
    QSqlQuery query("SELECT name, price, guests FROM Domivka");
    while (query.next()) {
        QString name = query.value(0).toString();
        double price = query.value(1).toDouble();
        int guests = query.value(2).toInt();
        domivkas.append(new Domivka(name, price, guests));
    }
    return domivkas;
}

QList<Hotel*> SqliteDBManager::loadHotelData() {
    QList<Hotel*> hotels;
    QSqlQuery query("SELECT name, price, rooms FROM Hotel");
    while (query.next()) {
        QString name = query.value(0).toString();
        double price = query.value(1).toDouble();
        int rooms = query.value(2).toInt();
        hotels.append(new Hotel(name, price, rooms));
    }
    return hotels;
}
