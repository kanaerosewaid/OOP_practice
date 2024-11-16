#ifndef DERIVED2_H
#define DERIVED2_H

#include "baseclass.h"

class Derived2 : public BaseClass {
public:
    Derived2(const QString &title, double amount) : title(title), amount(amount) {}
    QString toString() const override {
        return QString("Derived2: %1, %2").arg(title).arg(amount);
    }

private:
    QString title;
    double amount;
};

#endif // DERIVED2_H
