#include "dijkstradialog.h"
#include "ui_dijkstradialog.h"
/**
 * @brief Konstruktor für die Dijkstradialog-Klasse.
 *
 * Initialisiert das Dijkstra-Dialog-Fenster und richtet die UI ein.
 *
 * @param parent Der übergeordnete QWidget (standardmäßig nullptr).
 */
Dijkstradialog::Dijkstradialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dijkstradialog)
{
    ui->setupUi(this);

}
/**
 * @brief Destruktor für die Dijkstradialog-Klasse.
 *
 * Löscht die UI-Ressourcen.
 */
Dijkstradialog::~Dijkstradialog()
{
    delete ui;
}

/**
 * @brief Gibt den Namen der Startstadt zurück.
 *
 * Liest den Namen der Startstadt aus dem Dialog.
 *
 * @return Der Name der Startstadt als QString.
 */
QString Dijkstradialog::getCity1Name()
{
    startingCity = ui->startLct->text();
    return startingCity;
}

/**
 * @brief Gibt den Namen der Zielstadt zurück.
 *
 * Liest den Namen der Zielstadt aus dem Dialog.
 *
 * @return Der Name der Zielstadt als QString.
 */
QString Dijkstradialog::getCity2Name()
{
    endCity = ui->endLct->text();
    return endCity;
}
