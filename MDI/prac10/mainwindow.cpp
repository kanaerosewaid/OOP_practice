#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "derived1.h"
#include "derived2.h"

#include <QMessageBox>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect buttons to slots
    connect(ui->createDerived1Button, &QPushButton::clicked, this, &MainWindow::createDerived1);
    connect(ui->createDerived2Button, &QPushButton::clicked, this, &MainWindow::createDerived2);

    // Initialize models for the views
    derived1Model = new QStandardItemModel(this);
    ui->listWidgetDerived1->setModel(derived1Model);

    derived2Model = new QStandardItemModel(this);
    ui->listWidgetDerived2->setModel(derived2Model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createDerived1()
{
    bool ok;
    QString name = QInputDialog::getText(this, tr("Enter Name for Derived1"), tr("Name:"), QLineEdit::Normal, "", &ok);
    if (!ok || name.isEmpty()) return;

    int value = QInputDialog::getInt(this, tr("Enter Value for Derived1"), tr("Value:"), 0, 0, 100, 1, &ok);
    if (!ok) return;

    Derived1 *obj = new Derived1(name, value);
    derived1Objects.append(obj);

    // Add to model
    QStandardItem *item = new QStandardItem(obj->toString());
    derived1Model->appendRow(item);

    QMessageBox::information(this, tr("Object Created"), tr("Derived1 object created!") + "\n" + obj->toString());
}

void MainWindow::createDerived2()
{
    bool ok;
    QString title = QInputDialog::getText(this, tr("Enter Title for Derived2"), tr("Title:"), QLineEdit::Normal, "", &ok);
    if (!ok || title.isEmpty()) return;

    double amount = QInputDialog::getDouble(this, tr("Enter Amount for Derived2"), tr("Amount:"), 0.0, 0.0, 10000.0, 2, &ok);
    if (!ok) return;

    Derived2 *obj = new Derived2(title, amount);
    derived2Objects.append(obj);

    // Add to model
    QStandardItem *item = new QStandardItem(obj->toString());
    derived2Model->appendRow(item);

    QMessageBox::information(this, tr("Object Created"), tr("Derived2 object created!") + "\n" + obj->toString());
}

void MainWindow::clearDerived1()
{
    derived1Model->clear();
    derived1Objects.clear();
}

void MainWindow::clearDerived2()
{
    derived2Model->clear();
    derived2Objects.clear();
}
