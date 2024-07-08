#include "street.h"
/**
 * @brief Konstruktor der Street-Klasse.
 *
 * Initialisiert eine neue Instanz der Street-Klasse mit zwei Städten.
 *
 * @param stadt1 Zeiger auf die erste Stadt.
 * @param stadt2 Zeiger auf die zweite Stadt.
 */
Street::Street(City* stadt1, City* stadt2):
    stadt1(stadt1), stadt2(stadt2)
{

}
/**
 * @brief Destruktor der Street-Klasse.
 *
 * Löscht eine Instanz der Street-Klasse und gibt Ressourcen frei.
 */
Street::~Street()
{

}
/**
 * @brief Zeichnet die Straße in einer QGraphicsScene.
 *
 * Diese Methode zeichnet die Straße als Linie in einer gegebenen QGraphicsScene.
 *
 * @param scene Referenz auf die QGraphicsScene, in der die Straße gezeichnet werden soll.
 */
void Street::draw(QGraphicsScene &scene)
{
    int x1 = ((stadt1)->getX()) +5;
    int y1 = ((stadt1)->getY()) +5;
    int x2 = ((stadt2)->getX()) +5;
    int y2 = ((stadt2)->getY()) +5;

    QPen Pen;
    Pen.setColor(Qt::lightGray);
    Pen.setWidth(2);
    scene.addLine(x1, y1, x2, y2, Pen);
}
/**
 * @brief Gibt die erste Stadt der Straße zurück.
 *
 * @return Zeiger auf die erste Stadt.
 */
City* Street::getStadt1() const
{
    return stadt1;
}
/**
 * @brief Gibt die zweite Stadt der Straße zurück.
 *
 * @return Zeiger auf die zweite Stadt.
 */
City* Street::getStadt2() const
{
    return stadt2;
}
/**
 * @brief Gibt die ID der Straße aus.
 *
 * Diese Methode gibt eine Debug-Nachricht aus, die die Verbindung zwischen den beiden Städten beschreibt.
 */
void Street::strassen_id()
{
    qDebug() << "Verbindung zwischen " << stadt1->getName() << " und " << stadt2->getName();
}

/**
 * @brief Zeichnet die Straße in rot in einer QGraphicsScene. Bezeichnet der Dijkstra Weg.
 *
 * @param scene Referenz auf die QGraphicsScene, in der die Straße gezeichnet werden soll.
 */
void Street::drawRed(QGraphicsScene &scene)
{
    int x1 = ((stadt1)->getX()) +5;
    int y1 = ((stadt1)->getY()) +5;
    int x2 = ((stadt2)->getX()) +5;
    int y2 = ((stadt2)->getY()) +5;

    QPen Pen;
    Pen.setColor(Qt::red);
    Pen.setWidth(3);
    scene.addLine(x1, y1, x2, y2, Pen);
}
