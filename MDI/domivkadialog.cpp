#include "domivkadialog.h"
#include "ui_domivkadialog.h"
#include "QMessageBox"

DomivkaDialog::DomivkaDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DomivkaDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Створення об'єкта класу Domivka");
}

DomivkaDialog::~DomivkaDialog()
{
    delete ui;
}

void DomivkaDialog::on_pushButton_clicked()
{
    QString name = ui->lineEdit_name->text();
    double price = ui ->lineEdit_price->text().toDouble();
    int guests = ui->lineEdit_count->text().toInt();

    if (name.isEmpty() || !price || !guests) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Помилка створення об'єкта");
        msgBox.setText("Заповніть всі поля, або введіть коректні дані!");
        QPushButton *okButton = msgBox.addButton(QMessageBox::Ok);

        okButton->setText("Повернутись до вводу даних");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        return;
    }

    Domivka* domivka = new Domivka(name, price, guests);
    emit domivkaCreated(domivka);
    this -> close();
}
