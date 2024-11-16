#ifndef DERIVED1_H
#define DERIVED1_H

#include "baseclass.h"

class Derived1 : public BaseClass {
public:
    Derived1(const QString &name, int value) : name(name), value(value) {}
    QString toString() const override {
        return QString("Derived1: %1, %2").arg(name).arg(value);
    }

private:
    QString name;
    int value;
};

#endif // DERIVED1_H
