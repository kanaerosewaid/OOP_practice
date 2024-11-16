#ifndef ABITURIENT_H
#define ABITURIENT_H

#include <QString>

class Abiturient {
public:
    Abiturient(const QString& name, const QString& surname, const QString& address)
        : name(name), surname(surname), address(address) {}

    QString toString() const {
        return QString("Ім'я: %1\nПрізвище: %2\nАдреса: %3").arg(name).arg(surname).arg(address);
    }

private:
    QString name;
    QString surname;
    QString address;
};

#endif // ABITURIENT_H
