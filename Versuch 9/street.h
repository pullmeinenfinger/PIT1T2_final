#ifndef STREET_H
#define STREET_H

#include<QGraphicsView>
#include<QGraphicsItem>
#include "city.h"

class Street
{
public:
    Street(City* stadt1, City* stadt2);
    ~Street();
    void draw(QGraphicsScene &scene);
    City* getStadt1() const;
    City* getStadt2() const;
    void drawRed(QGraphicsScene &scene);
    void strassen_id();

private:
    City* stadt1;
    City* stadt2;
};

#endif // STREET_H
