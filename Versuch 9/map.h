#ifndef MAP_H
#define MAP_H

#include <QVector>
#include <QDebug>
#include "abstractmap.h"

class Map: public AbstractMap
{
public:
    Map();
    ~Map();
    void addCity(City*);
    bool addStreet(Street*);
    void draw(QGraphicsScene &scene);
    City* findCity(const QString gorad) const;
    QVector<Street*> getStreetList(const City* city) const;
    QVector<City*> getCityList();
    City* getOppositeCity(const Street* street, const City* city) const;
    double getLength(const Street* street) const;
    void deleteAll();

private:
    QVector <City*> staedte_Liste;
    QVector <Street*> strassen_Liste;
};

#endif // MAP_H
