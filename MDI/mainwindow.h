#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "domivka.h"
#include "hotel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_createDomivka_clicked();
    void on_pushButton_createHotel_clicked();
    void onDomivkaCreated(Domivka* domivka);
    void onHotelCreated(Hotel* hotel);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *domivkaModel;
    QStandardItemModel *hotelModel;

    void setupDomivkaTable();
    void setupHotelTable();
    void loadData();
};

#endif // MAINWINDOW_H
