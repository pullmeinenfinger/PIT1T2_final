#ifndef DIALOG_H
#define DIALOG_H

#include "city.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    City* newCity();
    QString getCity1Name();
    QString getCity2Name();
    void streetDialog();
    void cityDialog();

private:
    Ui::Dialog *ui;
    QString dialogCity;
    QString strasse;
    QString nameCity1;
    QString nameCity2;
    int x;
    int y;
};

#endif // DIALOG_H
