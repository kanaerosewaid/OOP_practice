#ifndef DOMIVKADIALOG_H
#define DOMIVKADIALOG_H

#include <QDialog>
#include "domivka.h"

namespace Ui {
class DomivkaDialog;
}

class DomivkaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DomivkaDialog(QWidget *parent = nullptr);
    ~DomivkaDialog();

signals:
    void domivkaCreated(Domivka* domivka);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DomivkaDialog *ui;
};

#endif // DOMIVKADIALOG_H
