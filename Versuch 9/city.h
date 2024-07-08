#ifndef CITY_H
#define CITY_H
#include <QDebug>
#include <QGraphicsView>
#include <QString>
#include <QGraphicsTextItem>
#include <QMainWindow>

class City
{
public:
    City(QString name, int x, int y);
    ~City();
    void draw(QGraphicsScene &scene);
    QString getName();
    int getX();
    int getY();

private:
    QString name;
    int x;
    int y;
};

#endif // CITY_H
