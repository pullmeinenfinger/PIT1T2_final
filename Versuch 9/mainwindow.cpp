#include "mainwindow.h"
#include "mapiofileinput.h"
#include "ui_mainwindow.h"
#include "city.h"
#include "street.h"
#include "dijkstra.h"
#include "dijkstradialog.h"
#include "uploaddialog.h"

#include <QString>
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QRandomGenerator>
#include <QWidget>
#include <QLineEdit>

/**
 * @brief Konstruktor für die MainWindow-Klasse.
 *
 * Initialisiert das Hauptfenster, die UI-Komponenten und die Karte.
 *
 * @param parent Der übergeordnete QWidget (standardmäßig nullptr).
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , map(*new Map)
    , mapio(new MapIoNrw)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    scene.addLine(0,0, 1, 1, QPen(Qt::transparent));

    ui->testStrasse->hide();
    ui->testmap->hide();
    ui->TestDrawCity->hide();
    ui->TestAbstractMap->hide();
    ui->TestDijkstra->hide();
    ui->testDialog->hide();
    ui->testSimple_Draw->hide();
    ui->pushButton_teste_was->hide();
    ui->buttonDijkstra->hide();

}
/**
 * @brief Destruktor für die MainWindow-Klasse.
 *
 * Löscht die UI-Ressourcen.
 */
MainWindow::~MainWindow()
{
    delete ui;
}



/**
 * @brief Behandelt das "Exit"-Aktionsevent.
 *
 * Schließt das Hauptfenster.
 */
void MainWindow::on_actionExit_triggered()
{
    close();
}

/**
 * @brief Behandelt das "Clear Scene"-Aktionsevent.
 *
 * Löscht alle Elemente der Szene und fügt eine transparente Linie hinzu.
 */
void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
    scene.addLine(0,0, 1, 1, QPen(Qt::transparent));
}
/**
 * @brief Behandelt das "Clear Map"-Aktionsevent.
 *
 * Löscht alle Elemente der Karte.
 */
void MainWindow::on_actionClear_Map_triggered()
{
    map.deleteAll();
}
/**
 * @brief Behandelt das "About"-Aktionsevent.
 *
 * Zeigt eine Informationsnachricht über das Programm an.
 */
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBoxAbout;
    msgBoxAbout.about(this, "Der StreetPlanner", "Dieses Programm ist eine UI App für Versuch 9 der Praktikum Informatik");
}
/**
 * @brief Behandelt das "Test Mode"-Aktionsevent.
 *
 * Schaltet den Testmodus ein oder aus und zeigt oder verbirgt die entsprechenden UI-Komponenten.
 */
void MainWindow::on_actionTest_Mode_triggered()
{
    if (ui->actionTest_Mode->isChecked()==false)
    {
        ui->testStrasse->hide();
        ui->testmap->hide();
        ui->TestDrawCity->hide();
        ui->TestAbstractMap->hide();
        ui->TestDijkstra->hide();
        ui->testDialog->hide();
        ui->testSimple_Draw->hide();
        ui->pushButton_teste_was->hide();

    }

    else if(ui->actionTest_Mode->isChecked()==true)
    {
        ui->testStrasse->show();
        ui->testmap->show();
        ui->TestDrawCity->show();
        ui->TestAbstractMap->show();
        ui->TestDijkstra->show();
        ui->testDialog->show();
        ui->testSimple_Draw->show();
        ui->pushButton_teste_was->show();

    }

}
/**
 * @brief Behandelt das "Reset Scene"-Aktionsevent.
 *
 * Setzt die Szene zurück und zeichnet die Karte neu.
 */
void MainWindow::on_actionReset_Scene_triggered()
{
    scene.clear();
    scene.addLine(0,0, 1, 1, QPen(Qt::transparent));
    map.draw(scene);
}
/**
 * @brief Behandelt das "Teste Was"-Button-Klickerevent.
 *
 * Führt eine Reihe von Debug-Ausgaben und Aktionen durch, einschließlich der Anzeige von Nachrichten und dem Zeichnen von zufälligen Rechtecken in der Szene.
 */
void MainWindow::on_pushButton_teste_was_clicked()
{
    QMessageBox testeWasMsg;
    qDebug() << "Sie haben den Knopf geklickt.";
    QString str;
    QString str1;
    int x;
    int y;
    QRandomGenerator generator;
    x =  generator.bounded(9);
    y = generator.bounded(9);

    str = ui -> lineEdit -> text ();
    qDebug() << "Ihre Eingabe: " << str;

    bool istZahl= false;
    int erhoehteZahl = str.toInt() + 4;
    testeWasMsg.information(this, "Konsole Ausgabe", "Sie haben den Knopf geklickt.\nRandom x Position: " + QString::number(x) + "  Random y Position: " + QString::number(y), QMessageBox::StandardButton());
    testeWasMsg.information(this, "Konsole Ausgabe", "Ihre Eingabe: " + str, QMessageBox::StandardButton());
    if(str.toInt(&istZahl))
    {
        qDebug() << "Ihre Eingabe ist eine Zahl:" << str;
        qDebug() << "Ihre Eingabe ist um 4 erhöht:" << erhoehteZahl;
        str1 = QString::number(erhoehteZahl);
        testeWasMsg.information(this, "Konsole Ausgabe", "Ihre Eingabe ist eine Zahl: " + str + "\nIhre Eingabe ist um 4 erhöht: " + str1, QMessageBox::StandardButton());

    }
    else
    {

        qDebug() << "Ihre Eingabe ist ein Text:"<< str;
        testeWasMsg.information(this, "Konsole Ausgabe", "Ihre Eingabe ist ein Text: " + str1, QMessageBox::StandardButton());
    }

    qDebug() << "Random x position:" << x << ", Random y position:" << y;

    scene.addRect(x, y, 30, 8, QPen(Qt::black),
                  QBrush(Qt::black, Qt::SolidPattern));
    scene.addRect(x, y + 8, 30, 8, QPen(Qt::red),
                  QBrush(Qt::red, Qt::SolidPattern));
    scene.addRect(x, y + 16, 30, 8, QPen(Qt::yellow),
                  QBrush(Qt::yellow, Qt::SolidPattern));
}

/**
 * @brief Behandelt das "Simple Draw"-Button-Klickerevent.
 *
 * Zeichnet ein einfaches Rechteck in der Szene.
 */
void MainWindow::on_testSimple_Draw_clicked()
{
    QPen Pen;
    Pen.setColor(Qt::blue);
    Pen.setWidth(3);
    scene.addRect(50, 20, 50, 100, Pen);
}
/**
 * @brief Behandelt das "Draw City"-Button-Klickerevent.
 *
 * Zeichnet zwei Städte in der Szene.
 */
void MainWindow::on_TestDrawCity_clicked()
{
    QMessageBox testCityMsg;
    City newCity1 = City("City 1", 10, 10);
    newCity1.draw(scene);

    City newCity2 = City("City 2", 90, 10);
    newCity2.draw(scene);
    qDebug() << "Zwei Städte werden gezeichnet";
    testCityMsg.information(this, "Konsole Ausgabe", "Zwei Städte werden gezeichnet", QMessageBox::StandardButton());
}

/**
 * @brief Behandelt das "Test Map"-Button-Klickerevent.
 *
 * Erstellt eine Testkarte, fügt Städte und Straßen hinzu und zeichnet diese in der Szene.
 */
void MainWindow::on_testmap_clicked()
{
    QMessageBox tstMapMsg;
    Map testMap;
    City newCityy1("City1", 40, 20);
    City newCityy2("City2", 90, 100);
    Street strasse1(&newCityy1, &newCityy2);
    testMap.addCity(&newCityy1);
    tstMapMsg.information(this,"Konsole Ausgabe", newCityy1.getName() + " wurde in die Karte hinzugefügt.", QMessageBox::StandardButton());
    testMap.addCity(&newCityy2);
    tstMapMsg.information(this,"Konsole Ausgabe", newCityy2.getName() + " wurde in die Karte hinzugefügt.", QMessageBox::StandardButton());
    testMap.addStreet(&strasse1);
    testMap.draw(scene);


}
/**
 * @brief Behandelt das "Test Street"-Button-Klickerevent.
 *
 * Erstellt zwei Städte und eine Straße zwischen ihnen und zeichnet diese in der Szene.
 */
void MainWindow::on_testStrasse_clicked()
{
        City* newCity1 = new City ("City1", 10, 20);
        City* newCity2 = new City ("City2", 80, 10);
        Street* strasse1 = new Street (newCity1, newCity2);
        newCity1->draw(scene);
        newCity2->draw(scene);
        strasse1->draw(scene);
}

/**
 * @brief Testet die Funktionalität der Map-Klasse.
 *
 * Führt verschiedene Tests auf der Map-Klasse durch, wie das Hinzufügen von Städten und Straßen,
 * das Finden von Städten und das Berechnen der Straßenlänge. Zeigt die Testergebnisse in einer QMessageBox an.
 */
void MainWindow::on_TestAbstractMap_clicked()
{
    Map testMap;
    QMessageBox testAbstractMsg;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    testAbstractMsg.information(this, "Konsole Ausgabe", "MapTest: Start Test of the Map", QMessageBox::StandardButton());
    {
        qDebug() << "MapTest: adding wrong street";
        testAbstractMsg.information(this, "Konsole Ausgabe", "MapTest: adding wrong street", QMessageBox::StandardButton());
        bool t1 = testMap.addStreet(s);
        if (t1)
        {
            qDebug() << "-Error: Street should not be added, if cities have not been added.";
            testAbstractMsg.critical(this, "Konsole Ausgabe", "Error: Street should not be added, if cities have not been added.", QMessageBox::StandardButton());
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testAbstractMsg.information(this, "Konsole Ausgabe", "MapTest: adding correct street", QMessageBox::StandardButton());
        testMap.addCity(a);
        testAbstractMsg.information(this,"Konsole Ausgabe", a->getName() + " wurde in die Karte hinzugefügt.", QMessageBox::StandardButton());
        testMap.addCity(b);
        testAbstractMsg.information(this,"Konsole Ausgabe", b->getName() + " wurde in die Karte hinzugefügt.", QMessageBox::StandardButton());
        bool t1 = testMap.addStreet(s);
        if (!t1)
        {
            qDebug() << "-Error: It should be possible to add this street.";
            testAbstractMsg.critical(this, "Konsole Ausgabe", "Error: It should be possible to add this street.", QMessageBox::StandardButton());
        }
    }

    {
        qDebug() << "MapTest: findCity";
        testAbstractMsg.information(this, "Konsole Ausgabe", "MapTest: findCity", QMessageBox::StandardButton());
        City* city = testMap.findCity("a");
        if (city != a)
        {
            qDebug() << "-Error: City a could not be found.";
            testAbstractMsg.critical(this, "Konsole Ausgabe", "Error: City a could not be found.", QMessageBox::StandardButton());
        }

        city = testMap.findCity("b");
        if (city != b)
        {
            qDebug() << "-Error: City b could not be found.";
            testAbstractMsg.critical(this, "Konsole Ausgabe", "Error: City b could not be found.", QMessageBox::StandardButton());
        }

        city = testMap.findCity("c");
        if (city != nullptr)
        {
            qDebug() << "-Error: If city could not be found 0 should be returned.";
            testAbstractMsg.critical(this, "Konsole Ausgabe", "Error: If city could not be found 0 should be returned.", QMessageBox::StandardButton());
        }

        testMap.addCity(c);
        testAbstractMsg.information(this,"Konsole Ausgabe", c->getName() + " wurde in die Karte hinzugefügt.", QMessageBox::StandardButton());
        testMap.addStreet(s2);

        {
            qDebug() << "MapTest: getOppositeCity";
            testAbstractMsg.information(this, "Konsole Ausgabe", "MapTest: getOppositeCity", QMessageBox::StandardButton());
            const City *city = testMap.getOppositeCity(s, a);
            if (city != b)
            {
                qDebug() << "-Error: Opposite city should be b.";
                testAbstractMsg.critical(this, "Konsole Ausgabe", "Error: Opposite city should be b.", QMessageBox::StandardButton());
            }

            city = map.getOppositeCity(s, c);
            if (city != nullptr)
            {
                qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
                testAbstractMsg.critical(this, "Konsole Ausgabe", "Error: Opposite city for a city which is not linked by given street should be 0.", QMessageBox::StandardButton());
            }
        }

        {
            qDebug() << "MapTest: streetLength";
            testAbstractMsg.information(this, "Konsole Ausgabe", "MapTest: streetLength", QMessageBox::StandardButton());
            double l = testMap.getLength(s2);
            double expectedLength = 223.6;
            // compare doubles with 5% tolerance
            if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            {
                qDebug() << "-Error: Street Length is not equal to the expected.";
                testAbstractMsg.critical(this, "Konsole Ausgabe", "Error: Street Length is not equal to the expected.", QMessageBox::StandardButton());
            }
        }

        {
            qDebug() << "MapTest: getStreetList";
            testAbstractMsg.information(this, "Konsole Ausgabe", "MapTest: getStreetList", QMessageBox::StandardButton());
            QVector<Street*> streetList1 = testMap.getStreetList(a);
            QVector<Street*> streetList2 = testMap.getStreetList(b);
            if (streetList1.size() != 1)
            {
                qDebug() << "-Error: One street should be found for city a.";
                testAbstractMsg.critical(this, "Konsole Ausgabe", "Error: One street should be found for city a.", QMessageBox::StandardButton());
            }
            else if (*streetList1.begin() != s)
            {
                qDebug() << "-Error: The wrong street has been found for city a.";
                testAbstractMsg.critical(this, "Konsole Ausgabe", "Error: The wrong street has been found for city a.", QMessageBox::StandardButton());
            }

            if (streetList2.size() != 2)
            {
                qDebug() << "-Error: Two streets should be found for city b.";
                testAbstractMsg.critical(this, "Konsole Ausgabe", "-Error: Two streets should be found for city b.", QMessageBox::StandardButton());
            }
        }
        qDebug() << "MapTest: End Test of the Map.";
        testAbstractMsg.information(this, "Konsole Ausgabe", "MapTest: End Test of the Map.", QMessageBox::StandardButton());
    }

}
/**
 * @brief Testet die Funktionalität des Dijkstra-Algorithmus.
 *
 * Erstellt eine Karte mit drei Städten und drei Straßen und berechnet den kürzesten Weg zwischen zwei Städten
 * unter Verwendung des Dijkstra-Algorithmus. Zeichnet die Karte und den kürzesten Weg auf der Szene.
 */
void MainWindow::on_TestDijkstra_clicked()
{
    Map testMap;
    QMessageBox tstDijkMsg;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    testMap.addCity(a);
    tstDijkMsg.information(this,"Konsole Ausgabe", a->getName() + " wurde in die Karte hinzugefügt.", QMessageBox::StandardButton());
    testMap.addCity(b);
    tstDijkMsg.information(this,"Konsole Ausgabe", b->getName() + " wurde in die Karte hinzugefügt.", QMessageBox::StandardButton());
    testMap.addCity(c);
    tstDijkMsg.information(this,"Konsole Ausgabe", c->getName() + " wurde in die Karte hinzugefügt.", QMessageBox::StandardButton());

    Street *s1 = new Street(a, b);
    Street *s2 = new Street(b, c);
    Street *s3 = new Street(a, c);
    testMap.addStreet(s1);
    testMap.addStreet(s2);
    testMap.addStreet(s3);

    testMap.draw(scene);

    QVector<Street*> kuerzesterWeg = Dijkstra::search(testMap, a->getName(), c->getName());

    for(auto it = kuerzesterWeg.begin(); it != kuerzesterWeg.end(); it++)
    {
        (*it)->drawRed(scene);
    }
}
/**
 * @brief Testet das Dialogfenster.
 *
 * Öffnet ein Dialogfenster und zeigt das Ergebnis des Dialogs in einer QMessageBox an.
 */
void MainWindow::on_testDialog_clicked()
{
    QMessageBox dialogMsg;
    Dialog dialogTest;
    int result = dialogTest.exec();
    QString str = QString::number(result);
    qDebug() << QString("Dialog result: %1").arg(result);
    dialogMsg.information(this, "Konsole Ausgabe", "Dialog result: " + str, QMessageBox::StandardButton());
}
/**
 * @brief Slot für den Klick auf den "Add Street" Button.
 *
 * Zeigt einen Dialog zum Hinzufügen einer Straße und gibt das Ergebnis in der Konsole aus.
 * Zeigt auch eine MessageBox mit dem Rückgabewert des Dialogs.
 */
void MainWindow::on_addStrasse_clicked()
{
    QMessageBox strtMsg;
    Dialog dialog;
    dialog.streetDialog();
    int i = dialog.exec();
    qDebug() << "Der Rückgabewert: " << i;
    strtMsg.information(this, "Konsole Ausgabe", "Der Rückgabewert: " + QString::number(i), QMessageBox::StandardButton());

    if (i == 1)
    {
        QString Name1 = dialog.getCity1Name();
        QString Name2 = dialog.getCity2Name();

        if(map.findCity(Name1) == nullptr || map.findCity(Name2) == nullptr)
        {
            strtMsg.critical(this, "Konsole Ausgabe", "please enter valid cities!", QMessageBox::StandardButton());
            qDebug() << "please enter valid cities!";
            return;
        }
        else
        {
            City* newCity1 = map.findCity(Name1);
            City* newCity2 = map.findCity(Name2);

            Street* strasse1 = new Street(newCity1, newCity2);
            if(map.addStreet(strasse1))
            {
                strasse1->draw(scene);
            }
        }
    }
    else
    {
        strtMsg.critical(this, "Konsole Ausgabe", "No new street has been added!", QMessageBox::StandardButton());
        qDebug() << "No new street has been added!";
    }
}

/**
* @brief Slot für den Klick auf den "Add City" Button.
*
* Zeigt einen Dialog zum Hinzufügen einer Stadt und gibt das Ergebnis in der Konsole aus.
* Zeigt auch eine MessageBox mit dem Rückgabewert des Dialogs.
*/
void MainWindow::on_addCity_clicked()
{
    QMessageBox ctyMsg;
    Dialog dialog;
    dialog.cityDialog();
    int i = dialog.exec();
    qDebug() << "Der Rückgabewert: " << i;
    ctyMsg.information(this, "Konsole Ausgabe", "Der Rückgabewert: " + QString::number(i), QMessageBox::StandardButton());
    if (i == 1)
    {
        City* dialogCity = dialog.newCity();
        map.addCity(dialogCity);
        ctyMsg.information(this,"Konsole Ausgabe", dialogCity->getName() + " wurde in die Karte hinzugefügt.", QMessageBox::StandardButton());
        dialogCity->draw(scene);
    }

    else
    {
        qDebug() << "Keine neue Stadt wurde hinzugefuegt.";
        ctyMsg.critical(this, "Konsole Ausgabe", "Keine neue Stadt wurde hinzugefuegt.", QMessageBox::StandardButton());
    }
}
/**
 * @brief Slot für den Klick auf den "Fill Map" Button.
 *
 * Füllt die Karte mit vordefinierten Daten und zeigt das Ergebnis in der Konsole an.
 * Zeigt auch eine MessageBox mit den hinzugefügten Städten.
 */
void MainWindow::on_FillMap_clicked()
{
    QMessageBox fillMsg;
    mapio->fillMap(map);
    map.draw(scene);
    fillMsg.information(this,"Konsole Ausgabe", map.getCityList()[0]->getName() + " wurde in die Karte hinzugefügt.\n" +  map.getCityList()[1]->getName() + " wurde in die Karte hinzugefügt.\n" + map.getCityList()[2]->getName() + " wurde in die Karte hinzugefügt.\n" + map.getCityList()[3]->getName() + " wurde in die Karte hinzugefügt.", QMessageBox::StandardButton());
}

/**
 * @brief Slot für den Klick auf den "Dijkstra Dialog" Button.
 *
 * Zeigt einen Dialog für den Dijkstra-Algorithmus und gibt das Ergebnis in der Konsole aus.
 * Zeigt auch eine MessageBox mit dem Rückgabewert des Dialogs.
 */
void MainWindow::on_pushButton_clicked()
{
    QMessageBox dijkMsg;
    Dijkstradialog dijkstra;
    int i = dijkstra.exec();
    qDebug() << "Der Rückgabewert: " << i;
    dijkMsg.information(this, "Konsole Ausgabe", "Der Rückgabewert: " + QString::number(i), QMessageBox::StandardButton());
    if (i == 1)
    {
        QString Name1 = dijkstra.getCity1Name();
        QString Name2 = dijkstra.getCity2Name();

        if(map.findCity(Name1) == nullptr || map.findCity(Name2) == nullptr)
        {
            qDebug() << "please enter valid cities!";
            dijkMsg.critical(this, "Konsole Ausgabe", "please enter valid cities!", QMessageBox::StandardButton());
            return;
        }
        else if(map.findCity(Name1) != nullptr && map.findCity(Name2) != nullptr)
        {
            QVector<Street*> kuerzesterWeg = Dijkstra::search(map, Name1, Name2);

            for(auto it = kuerzesterWeg.begin(); it != kuerzesterWeg.end(); it++)
            {
                (*it)->drawRed(scene);

            }
        }
    }
    else
    {
        qDebug() << "Dijkstra is cancelled.";
        dijkMsg.critical(this, "Konsole Ausgabe", "Dijkstra is cancelled!", QMessageBox::StandardButton());
    }


}

/**
 * @brief Slot für den Klick auf den "Upload Button" Button.
 *
 * Zeigt einen Dialog für den Dateiupload und füllt die Karte mit den hochgeladenen Daten.
 * Zeigt auch eine MessageBox mit dem Rückgabewert des Dialogs.
 */
void MainWindow::on_uploadButton_clicked()
{
    QMessageBox uploadMsg;
    Uploaddialog upload;
    int i = upload.exec();
    qDebug() << "Der Rückgabewert: " << i;
    uploadMsg.information(this, "Konsole Ausgabe", "Der Rückgabewert: " + QString::number(i), QMessageBox::StandardButton());
    if (i == 1)
    {
        MapIoFileinput files(upload.getFileCities(),upload.getFileStreets());
        files.fillMap(map);
        map.draw(scene);
    }
    else
    {
        qDebug() << "File upload is cancelled.";
        uploadMsg.critical(this, "Konsole Ausgabe", "File upload is cancelled.", QMessageBox::StandardButton());
    }


}

///Leer Funktionaufruf wegen QT gelöschte Button Slot Probleme
void MainWindow::on_buttonDijkstra_clicked()
{
}






