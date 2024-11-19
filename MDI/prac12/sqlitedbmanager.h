#ifndef SQLITEDBMANAGER_H
#define SQLITEDBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include "domivka.h"
#include "hotel.h"

class SqliteDBManager {
public:
    static SqliteDBManager& instance() {
        static SqliteDBManager instance;
        return instance;
    }

    bool addDomivka(const Domivka& domivka);
    bool addHotel(const Hotel& hotel);
    QList<Domivka*> loadDomivkaData();
    QList<Hotel*> loadHotelData();

private:
    SqliteDBManager();
    ~SqliteDBManager();
    void setupLogging();
    QSqlDatabase db;
};

#endif // SQLITEDBMANAGER_H
