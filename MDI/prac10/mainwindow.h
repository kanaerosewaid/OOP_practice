#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QStandardItemModel>

#include "derived1.h"
#include "derived2.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void createDerived1();
    void createDerived2();
    void clearDerived1();
    void clearDerived2();

private:
    Ui::MainWindow *ui;

    QVector<Derived1*> derived1Objects;
    QVector<Derived2*> derived2Objects;

    QStandardItemModel *derived1Model;
    QStandardItemModel *derived2Model;
};

#endif // MAINWINDOW_H
