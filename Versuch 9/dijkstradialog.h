#include <QDialog>

namespace Ui {
class Dijkstradialog;
}

class Dijkstradialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dijkstradialog(QWidget *parent = nullptr);
    ~Dijkstradialog();
    QString getCity1Name();
    QString getCity2Name();

private:
    Ui::Dijkstradialog *ui;
    QString startingCity;
    QString endCity;
};
