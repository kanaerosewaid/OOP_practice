#include "Derived1Dialog.h"

Derived1Dialog::Derived1Dialog(QWidget *parent) :
    QDialog(parent),
    obj(nullptr)
{
    nameEdit = new QLineEdit(this);
    valueEdit = new QLineEdit(this);
    createButton = new QPushButton("Create", this);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(nameEdit);
    layout->addWidget(valueEdit);
    layout->addWidget(createButton);

    setLayout(layout);

    connect(createButton, &QPushButton::clicked, this, &Derived1Dialog::createObject);
}

Derived1Dialog::~Derived1Dialog() {}

Derived1* Derived1Dialog::getObject()
{
    return obj;
}

void Derived1Dialog::createObject()
{
    obj = new Derived1(nameEdit->text(), valueEdit->text().toInt());
    accept();  // Close the dialog
}
