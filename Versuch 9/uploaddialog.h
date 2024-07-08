#ifndef UPLOADDIALOG_H
#define UPLOADDIALOG_H

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class Uploaddialog;
}

class Uploaddialog : public QDialog
{
    Q_OBJECT

public:
    explicit Uploaddialog(QWidget *parent = nullptr);
    ~Uploaddialog();
    QString getFileCities();
    QString getFileStreets();


private slots:
    void on_uploadButton1_clicked();

    void on_uploadButton2_clicked();

private:
    Ui::Uploaddialog *ui;
    QString filePath1;
    QString filePath2;
};

#endif // UPLOADDIALOG_H
