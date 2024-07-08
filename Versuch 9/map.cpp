#include "map.h"
/**
 * @brief Konstruktor der Map-Klasse.
 *
 * Initialisiert eine neue Instanz der Map-Klasse.
 */
Map::Map()
{

}
/**
 * @brief Destruktor der Map-Klasse.
 *
 * Löscht eine Instanz der Map-Klasse und gibt Ressourcen frei.
 */
Map::~Map()
{
}
/**
 * @brief Löscht alle Städte und Straßen von der Karte.
 */
void Map::deleteAll()
{

    //for(QVector<City*>::const_iterator it = staedte_Liste.begin(); it != staedte_Liste.end(); it++)
    staedte_Liste.erase(staedte_Liste.constBegin(), staedte_Liste.constEnd());
    strassen_Liste.erase(strassen_Liste.constBegin(), strassen_Liste.constEnd());
}
/**
 * @brief Fügt eine Stadt zur Karte hinzu.
 *
 * @param stadt Ein Zeiger auf die hinzuzufügende Stadt.
 */
void Map::addCity(City* stadt)
{
    staedte_Liste.append(stadt);
    qDebug() << stadt->getName() << "wurde in die Karte hinzugefügt.";
}
/**
 * @brief Sucht eine Stadt nach ihrem Namen.
 *
 * @param cityName Der Name der zu suchenden Stadt.
 * @return Ein Zeiger auf die gefundene Stadt oder nullptr, falls die Stadt nicht gefunden wurde.
 */
City* Map::findCity(const QString cityName) const
{
    for(QVector<City*>::const_iterator it = staedte_Liste.begin(); it != staedte_Liste.end(); it++)
    {
        if ((*it)->getName() == cityName)
        {
            return *it;
        }
    }

    return nullptr;
}
/**
 * @brief Gibt eine Liste von Straßen zurück, die mit einer gegebenen Stadt verbunden sind.
 *
 * @param city Ein Zeiger auf die Stadt, deren Straßenliste zurückgegeben werden soll.
 * @return Eine QVector-Liste von Zeigern auf die Straßen.
 */
QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector <Street*> cityStreetList;
    for(QVector<Street*>::const_iterator it = strassen_Liste.begin(); it != strassen_Liste.end(); it++)
    {
        if(city == (*it)->getStadt1() || city == (*it)->getStadt2())
        {
            cityStreetList.append(*it);
        }
    }

    return cityStreetList;
}
/**
 * @brief Gibt eine Liste von Städten zurück, die auf der Karte existieren.
 *
 * @return Eine QVector-Liste von Zeigern auf die Städte.
 */
QVector<City*> Map::getCityList()
{
    return staedte_Liste;
}
/**
 * @brief Gibt die gegenüberliegende Stadt einer Straße zurück.
 *
 * @param street Ein Zeiger auf die Straße.
 * @param city Ein Zeiger auf eine der Städte der Straße.
 * @return Ein Zeiger auf die gegenüberliegende Stadt oder nullptr, falls die gegebene Stadt nicht Teil der Straße ist.
 */
City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if (city == street->getStadt1())
    {
        return street->getStadt2();
    }

    else if (city == street->getStadt2())
    {
        return street->getStadt1();
    }

    else
    {
        return nullptr;
    }
}
/**
 * @brief Berechnet die Länge einer Straße.
 *
 * @param street Ein Zeiger auf die Straße, deren Länge berechnet werden soll.
 * @return Die Länge der Straße.
 */
double Map::getLength(const Street* street) const
{
    double x1 = street->getStadt1()->getX();
    double x2 = street->getStadt2()->getX();
    double y1 = street->getStadt1()->getY();
    double y2 = street->getStadt2()->getY();

    double x_laenge = abs(x2 - x1);
    double y_laenge = abs(y2 - y1);

    double length = sqrt(x_laenge*x_laenge + y_laenge*y_laenge);

    return length;
}
/**
 * @brief Fügt eine Straße zur Karte hinzu.
 *
 * @param strasse Ein Zeiger auf die hinzuzufügende Straße.
 * @return True, falls die Straße erfolgreich hinzugefügt wurde, andernfalls false.
 */
bool Map::addStreet(Street* strasse)
{
    City* city1 = strasse->getStadt1();
    City* city2 = strasse->getStadt2();

    if (findCity(city1->getName()) != nullptr && findCity(city2->getName()) != nullptr)
    {
        strassen_Liste.append(strasse);
        return true;
    }

    else
    {
        return false;
    }
}
/**
 * @brief Zeichnet die Karte in einer gegebenen QGraphicsScene.
 *
 * @param scene Die Szene, in der die Karte gezeichnet wird.
 */
void Map::draw(QGraphicsScene &scene)
{
    for(QVector<City*>::iterator it = staedte_Liste.begin(); it != staedte_Liste.end(); it++)
    {
        (*it)->draw(scene);
    }
    for(QVector<Street*>::iterator it1 = strassen_Liste.begin(); it1 != strassen_Liste.end(); it1++)
    {
        (*it1)->draw(scene);
    }
}

