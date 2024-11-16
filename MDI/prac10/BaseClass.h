#ifndef BASECLASS_H
#define BASECLASS_H

#include <QString>

class BaseClass {
public:
    virtual ~BaseClass() = default;
    virtual QString toString() const = 0;
};

#endif // BASECLASS_H
