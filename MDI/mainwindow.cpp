#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "domivkadialog.h"
#include "hoteldialog.h"
// #include "sqlitedbmanager.h" // Закоментовано
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("Практична робота №10");

    domivkaModel = new QStandardItemModel(this);
    hotelModel = new QStandardItemModel(this);
    setupDomivkaTable();
    setupHotelTable();

    // loadData(); // Закоментовано
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
    /*
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
    */
}

void MainWindow::on_pushButton_clicked()
{
    /*
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
    */
}
