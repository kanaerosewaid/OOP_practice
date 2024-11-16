#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Abiturient.h"

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
    void on_createButton_clicked();  // Слот для натискання кнопки

    void on_actionCreate_triggered();   // Слот для створення об'єкта
    void on_actionShow_triggered();     // Слот для відображення об'єкта
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    Abiturient *abiturient; // Вказівник на об'єкт класу Abiturient
};

#endif // MAINWINDOW_H
