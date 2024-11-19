#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "domivkadialog.h"
#include "hoteldialog.h"
<<<<<<< HEAD
// #include "sqlitedbmanager.h" // Закоментовано
=======
#include "sqlitedbmanager.h"
>>>>>>> PR11
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("Практична робота №10");

    domivkaModel = new QStandardItemModel(this);
    hotelModel = new QStandardItemModel(this);
    setupDomivkaTable();
    setupHotelTable();

<<<<<<< HEAD
    // loadData(); // Закоментовано
=======
    loadData();
>>>>>>> PR11
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_3_clicked() {
    QApplication::exit();
}

void MainWindow::on_pushButton_createDomivka_clicked() {
    DomivkaDialog dialog;
    connect(&dialog, &DomivkaDialog::domivkaCreated, this, &MainWindow::onDomivkaCreated);
    dialog.exec();
}

void MainWindow::on_pushButton_createHotel_clicked() {
    HotelDialog dialog;
    connect(&dialog, &HotelDialog::hotelCreated, this, &MainWindow::onHotelCreated);
    dialog.exec();
}

void MainWindow::onDomivkaCreated(Domivka* domivka) {
<<<<<<< HEAD
    // if (SqliteDBManager::instance().addDomivka(*domivka)) { // Закоментовано
    QList<QStandardItem*> row;
    row << new QStandardItem(domivka->getName())
        << new QStandardItem(QString::number(domivka->getPrice()))
        << new QStandardItem(QString::number(domivka->getGuests()));
    domivkaModel->appendRow(row);
    // } // Закоментовано
}

void MainWindow::onHotelCreated(Hotel* hotel) {
    // if (SqliteDBManager::instance().addHotel(*hotel)) { // Закоментовано
    QList<QStandardItem*> row;
    row << new QStandardItem(hotel->getName())
        << new QStandardItem(QString::number(hotel->getPrice()))
        << new QStandardItem(QString::number(hotel->getRooms()));
    hotelModel->appendRow(row);
    // } // Закоментовано
=======
    if (SqliteDBManager::instance().addDomivka(*domivka)) {
        QList<QStandardItem*> row;
        row << new QStandardItem(domivka->getName())
            << new QStandardItem(QString::number(domivka->getPrice()))
            << new QStandardItem(QString::number(domivka->getGuests()));
        domivkaModel->appendRow(row);
    }
}

void MainWindow::onHotelCreated(Hotel* hotel) {
    if (SqliteDBManager::instance().addHotel(*hotel)) {
        QList<QStandardItem*> row;
        row << new QStandardItem(hotel->getName())
            << new QStandardItem(QString::number(hotel->getPrice()))
            << new QStandardItem(QString::number(hotel->getRooms()));
        hotelModel->appendRow(row);
    }
>>>>>>> PR11
}

void MainWindow::setupDomivkaTable() {
    domivkaModel->setHorizontalHeaderLabels({"Адреса", "Ціна", "Кількість гостей"});
    ui->tableView_domivka->setModel(domivkaModel);
}

void MainWindow::setupHotelTable() {
    hotelModel->setHorizontalHeaderLabels({"Адреса", "Ціна", "Кількість кімнат"});
    ui->tableView_hotel->setModel(hotelModel);
}

void MainWindow::loadData() {
<<<<<<< HEAD
    /*
=======
>>>>>>> PR11
    auto domivkas = SqliteDBManager::instance().loadDomivkaData();
    for (Domivka* domivka : domivkas) {
        QList<QStandardItem*> row;
        row << new QStandardItem(domivka->getName())
            << new QStandardItem(QString::number(domivka->getPrice()))
            << new QStandardItem(QString::number(domivka->getGuests()));
        domivkaModel->appendRow(row);
    }

    auto hotels = SqliteDBManager::instance().loadHotelData();
    for (Hotel* hotel : hotels) {
        QList<QStandardItem*> row;
        row << new QStandardItem(hotel->getName())
            << new QStandardItem(QString::number(hotel->getPrice()))
            << new QStandardItem(QString::number(hotel->getRooms()));
        hotelModel->appendRow(row);
    }
<<<<<<< HEAD
    */
=======
>>>>>>> PR11
}

void MainWindow::on_pushButton_clicked()
{
<<<<<<< HEAD
    /*
=======
>>>>>>> PR11
    QSqlQuery query;

    if (query.exec("DELETE FROM Domivka")) {
        QMessageBox::information(this, "Успіх", "Дані в таблиці Domivka були успішно очищені.");
    } else {
        QMessageBox::warning(this, "Помилка", "Не вдалося очистити таблицю apartments: " + query.lastError().text());
    }


    if (query.exec("DELETE FROM Hotel")) {
        QMessageBox::information(this, "Успіх", "Дані в таблиці Domivka були успішно очищені.");
    } else {
        QMessageBox::warning(this, "Помилка", "Не вдалося очистити таблицю apartments: " + query.lastError().text());
    }
<<<<<<< HEAD
    */
}
=======
}

>>>>>>> PR11
