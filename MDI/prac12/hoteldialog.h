#ifndef HOTELDIALOG_H
#define HOTELDIALOG_H

#include <QDialog>
#include "hotel.h"

namespace Ui {
class HotelDialog;
}

class HotelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HotelDialog(QWidget *parent = nullptr);
    ~HotelDialog();

signals:
    void hotelCreated(Hotel* hotel);

private slots:
    void on_pushButton_clicked();

private:
    Ui::HotelDialog *ui;
};

#endif // HOTELDIALOG_H
