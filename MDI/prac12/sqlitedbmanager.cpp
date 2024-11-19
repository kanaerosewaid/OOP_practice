#include "sqlitedbmanager.h"

void logMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    QFile logFile("logfile.txt");
    logFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream out(&logFile);

    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    switch (type) {
    case QtDebugMsg:
        out << timestamp << " [DEBUG]: " << msg << "\n";
        break;
    case QtWarningMsg:
        out << timestamp << " [WARNING]: " << msg << "\n";
        break;
    case QtCriticalMsg:
        out << timestamp << " [CRITICAL]: " << msg << "\n";
        break;
    case QtFatalMsg:
        out << timestamp << " [FATAL]: " << msg << "\n";
        abort();
    }
}

SqliteDBManager::SqliteDBManager() {
    setupLogging(); // Включення логування у файл

    try {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("database.db");
        if (!db.open()) {
            qCritical() << "Не вдалося відкрити базу даних:" << db.lastError().text();
            throw std::runtime_error("Database connection failed");
        }

        QSqlQuery query;
        if (!query.exec("CREATE TABLE IF NOT EXISTS Domivka (name TEXT, price REAL, guests INTEGER)")) {
            qWarning() << "Помилка створення таблиці Domivka:" << query.lastError().text();
        }

        if (!query.exec("CREATE TABLE IF NOT EXISTS Hotel (name TEXT, price REAL, rooms INTEGER)")) {
            qWarning() << "Помилка створення таблиці Hotel:" << query.lastError().text();
        }
    } catch (const std::exception &e) {
        qCritical() << "Виняток у конструкторі SqliteDBManager:" << e.what();
    }
}

SqliteDBManager::~SqliteDBManager() {
    db.close();
}

void SqliteDBManager::setupLogging() {
    // Використовуємо стандартну функцію, замість lambda-функції
    qInstallMessageHandler(logMessageHandler);
}

bool SqliteDBManager::addDomivka(const Domivka& domivka) {
    try {
        QSqlQuery query;
        query.prepare("INSERT INTO Domivka (name, price, guests) VALUES (?, ?, ?)");
        query.bindValue(0, domivka.getName());
        query.bindValue(1, domivka.getPrice());
        query.bindValue(2, domivka.getGuests());

        if (!query.exec()) {
            qWarning() << "Помилка додавання Domivka:" << query.lastError().text();
            throw std::runtime_error("Failed to add Domivka");
        }
        return true;
    } catch (const std::exception &e) {
        qCritical() << "Виняток у addDomivka:" << e.what();
        return false;
    }
}

bool SqliteDBManager::addHotel(const Hotel& hotel) {
    try {
        QSqlQuery query;
        query.prepare("INSERT INTO Hotel (name, price, rooms) VALUES (?, ?, ?)");
        query.bindValue(0, hotel.getName());
        query.bindValue(1, hotel.getPrice());
        query.bindValue(2, hotel.getRooms());

        if (!query.exec()) {
            qWarning() << "Помилка додавання Hotel:" << query.lastError().text();
            throw std::runtime_error("Failed to add Hotel");
        }
        return true;
    } catch (const std::exception &e) {
        qCritical() << "Виняток у addHotel:" << e.what();
        return false;
    }
}

QList<Domivka*> SqliteDBManager::loadDomivkaData() {
    QList<Domivka*> domivkas;
    try {
        QSqlQuery query("SELECT name, price, guests FROM Domivka");
        if (!query.exec()) {
            qWarning() << "Помилка виконання SQL-запиту для Domivka:" << query.lastError().text();
            throw std::runtime_error("Failed to load Domivka data");
        }

        while (query.next()) {
            QString name = query.value(0).toString();
            double price = query.value(1).toDouble();
            int guests = query.value(2).toInt();
            domivkas.append(new Domivka(name, price, guests));
        }
    } catch (const std::exception &e) {
        qCritical() << "Виняток у loadDomivkaData:" << e.what();
    }
    return domivkas;
}

QList<Hotel*> SqliteDBManager::loadHotelData() {
    QList<Hotel*> hotels;
    try {
        QSqlQuery query("SELECT name, price, rooms FROM Hotel");
        if (!query.exec()) {
            qWarning() << "Помилка виконання SQL-запиту для Hotel:" << query.lastError().text();
            throw std::runtime_error("Failed to load Hotel data");
        }

        while (query.next()) {
            QString name = query.value(0).toString();
            double price = query.value(1).toDouble();
            int rooms = query.value(2).toInt();
            hotels.append(new Hotel(name, price, rooms));
        }
    } catch (const std::exception &e) {
        qCritical() << "Виняток у loadHotelData:" << e.what();
    }
    return hotels;
}
