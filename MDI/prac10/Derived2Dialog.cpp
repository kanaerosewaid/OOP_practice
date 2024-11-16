#include "Derived2Dialog.h"

Derived2Dialog::Derived2Dialog(QWidget *parent) :
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

    connect(createButton, &QPushButton::clicked, this, &Derived2Dialog::createObject);
}

Derived2Dialog::~Derived2Dialog() {}

Derived2* Derived2Dialog::getObject()
{
    return obj;
}

void Derived2Dialog::createObject()
{
    obj = new Derived2(nameEdit->text(), valueEdit->text().toInt());
    accept();  // Close the dialog
}
