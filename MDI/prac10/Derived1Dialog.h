#ifndef DERIVED1DIALOG_H
#define DERIVED1DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "Derived1.h"

class Derived1Dialog : public QDialog
{
    Q_OBJECT

public:
    Derived1Dialog(QWidget *parent = nullptr);
    ~Derived1Dialog();
    Derived1* getObject();

private slots:
    void createObject();

private:
    QLineEdit *nameEdit;
    QLineEdit *valueEdit;
    QPushButton *createButton;
    Derived1 *obj;
};

#endif // DERIVED1DIALOG_H
