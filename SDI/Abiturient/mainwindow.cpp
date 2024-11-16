#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abiturient.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_createButton_clicked()
{
    QString name = ui->nameLineEdit->text();
    QString surname = ui->surnameLineEdit->text();
    QString address = ui->addressLineEdit->text();

    if (name.isEmpty() || surname.isEmpty() || address.isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Будь ласка, заповніть всі обов'язкові поля.");
    } else {
        abiturient = new Abiturient(name, surname, address);
        QMessageBox::information(this, "Успіх", abiturient->toString());
    }
}


// Слот для створення об'єкта
void MainWindow::on_actionCreate_triggered()
{
    QString name = ui->nameLineEdit->text();
    QString surname = ui->surnameLineEdit->text();
    QString address = ui->addressLineEdit->text();

    if (name.isEmpty() || surname.isEmpty() || address.isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Будь ласка, заповніть всі обов'язкові поля.");
    } else {
        abiturient = new Abiturient(name, surname, address);  // Створення об'єкта
        QMessageBox::information(this, "Успіх", abiturient->toString());
    }
}

// Слот для відображення об'єкта
void MainWindow::on_actionShow_triggered()
{
    if (abiturient != nullptr) {
        QMessageBox::information(this, "Об'єкт", abiturient->toString());
    } else {
        QMessageBox::warning(this, "Помилка", "Об'єкт ще не створений.");
    }
}

// Слот для виходу
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();  // Вихід з програми
}
