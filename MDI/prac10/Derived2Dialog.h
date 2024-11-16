#ifndef DERIVED1DIALOG_H
#define DERIVED1DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "Derived2.h"

class Derived2Dialog : public QDialog
{
    Q_OBJECT

public:
    Derived2Dialog(QWidget *parent = nullptr);
    ~Derived2Dialog();
    Derived2* getObject();

private slots:
    void createObject();

private:
    QLineEdit *nameEdit;
    QLineEdit *valueEdit;
    QPushButton *createButton;
    Derived2 *obj;
};

#endif // DERIVED1DIALOG_H
