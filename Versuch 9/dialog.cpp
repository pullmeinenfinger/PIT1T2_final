#include "dialog.h"
#include "ui_dialog.h"

#include <QDebug>
/**
 * @brief Konstruktor für die Dialog-Klasse.
 *
 * Initialisiert das Dialog-Fenster und richtet die UI ein.
 *
 * @param parent Der übergeordnete QWidget (standardmäßig nullptr).
 */
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}
/**
 * @brief Destruktor für die Dialog-Klasse.
 *
 * Löscht die UI-Ressourcen.
 */
Dialog::~Dialog()
{
    delete ui;
}
/**
 * @brief Zeigt das Dialog-Fenster für das Hinzufügen einer Straße an.
 *
 * Versteckt die Eingabefelder für die Stadt und zeigt die Eingabefelder für die Straße.
 */
void Dialog::streetDialog()
{
    ui->nameStadt1->show();
    ui->nameStadt2->show();
    ui->label_5->show();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->nameStadt->hide();
    ui->xAchse->hide();
    ui->yAchse->hide();
    this->setWindowTitle("Add Street");
    this->setFixedSize(minimumSize());
}
/**
 * @brief Zeigt das Dialog-Fenster für das Hinzufügen einer Stadt an.
 *
 * Versteckt die Eingabefelder für die Straße und zeigt die Eingabefelder für die Stadt.
 */
void Dialog::cityDialog()
{
    ui->nameStadt1->hide();
    ui->nameStadt2->hide();
    ui->label_5->hide();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->nameStadt->show();
    ui->xAchse->show();
    ui->yAchse->show();
    this->setWindowTitle("Add City");
    this->setFixedSize(minimumSize());
}
/**
 * @brief Erstellt eine neue Stadt basierend auf den Benutzereingaben.
 *
 * Liest die Eingabewerte für die Stadt aus dem Dialog und gibt ein neues City-Objekt zurück.
 *
 * @return Ein Zeiger auf das neue City-Objekt.
 */
City* Dialog::newCity()
{
    dialogCity = ui->nameStadt->text();
    qDebug() << dialogCity;
    bool ok;

    x = ui->xAchse->text().toInt(&ok);

    if (ok == false)
    {
        qDebug() << "Bitte geben Sie eine Zahl ein!";
    }
    else
    {
        qDebug() << y;
    }

    y = ui->yAchse->text().toInt(&ok);
    if (ok == false)
    {
        qDebug() << "Bitte geben Sie eine Zahl ein!";
    }
    else
    {
        qDebug() << y;
    }

    return  new City(dialogCity, x, y);
}
/**
 * @brief Gibt den Namen der ersten Stadt zurück.
 *
 * Liest den Namen der ersten Stadt aus dem Dialog.
 *
 * @return Der Name der ersten Stadt als QString.
 */
QString Dialog::getCity1Name()
{
    nameCity1 = ui->nameStadt1->text();
    return nameCity1;
}
/**
 * @brief Gibt den Namen der zweiten Stadt zurück.
 *
 * Liest den Namen der zweiten Stadt aus dem Dialog.
 *
 * @return Der Name der zweiten Stadt als QString.
 */
QString Dialog::getCity2Name()
{
    nameCity2 = ui->nameStadt2->text();
    return nameCity2;
}
