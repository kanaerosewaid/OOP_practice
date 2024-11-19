#include "hoteldialog.h"
#include "ui_hoteldialog.h"
#include "QMessageBox"

HotelDialog::HotelDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HotelDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Створення об'єкта класу Hotel");
}

HotelDialog::~HotelDialog()
{
    delete ui;
}

void HotelDialog::on_pushButton_clicked()
{
    QString name = ui->lineEdit_name->text();
    double price = ui->lineEdit_price->text().toDouble();
    int rooms = ui->lineEdit_rooms->text().toInt();

    if (name.isEmpty() || !price || !rooms) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Помилка створення об'єкта");
        msgBox.setText("Заповніть всі поля, або введіть коректні дані!");
        QPushButton *okButton = msgBox.addButton(QMessageBox::Ok);

        okButton->setText("Повернутись до вводу даних");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        return;
    }

    Hotel* hotel = new Hotel(name, price, rooms);
    emit hotelCreated(hotel);
    this->close();
}
