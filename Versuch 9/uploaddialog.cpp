#include "uploaddialog.h"
#include "ui_uploaddialog.h"

/**
 * @brief Konstruktor der Uploaddialog-Klasse.
 *
 * Initialisiert eine neue Instanz der Uploaddialog-Klasse.
 *
 * @param parent Zeiger auf das übergeordnete Widget.
 */
Uploaddialog::Uploaddialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Uploaddialog)
{
    ui->setupUi(this);
}
/**
 * @brief Destruktor der Uploaddialog-Klasse.
 *
 * Löscht eine Instanz der Uploaddialog-Klasse und gibt Ressourcen frei.
 */
Uploaddialog::~Uploaddialog()
{
    delete ui;
}

/**
 * @brief Slot für den Klick auf den ersten Upload-Button.
 *
 * Öffnet einen QFileDialog zum Auswählen einer Stadtdatei und zeigt den Dateipfad im zugehörigen Textfeld an.
 */
void Uploaddialog::on_uploadButton1_clicked()
{
    QFileDialog upload;

    filePath1 = upload.getOpenFileName(this,tr("Open City File"),"C:\\Users\\baris\\Documents\\Streetplanner" , tr("Text Files (*.txt)"));
    ui->path1->setText(filePath1);
    qDebug() << filePath1;

}



/**
 * @brief Slot für den Klick auf den zweiten Upload-Button welche für Strassen Datei auswählt.
 *
 * Öffnet einen QFileDialog zum Auswählen einer Straßendatei und zeigt den Dateipfad im zugehörigen Textfeld an.
 */
void Uploaddialog::on_uploadButton2_clicked()
{
    QFileDialog upload;

    filePath2 = upload.getOpenFileName(this,tr("Open Street File"),"C:\\Users\\baris\\Documents\\Streetplanner" , tr("Text Files (*.txt)"));
    ui->path2->setText(filePath2);
    qDebug() << filePath2;

}

/**
 * @brief Gibt den Dateipfad der hochgeladenen Stadtdatei zurück.
 *
 * @return Der Dateipfad der hochgeladenen Stadtdatei als QString.
 */
QString Uploaddialog::getFileCities()
{
    return filePath1;
}

/**
 * @brief Gibt den Dateipfad der hochgeladenen Straßendatei zurück.
 *
 * @return Der Dateipfad der hochgeladenen Straßendatei als QString.
 */
QString Uploaddialog::getFileStreets()
{
    return filePath2;
}
