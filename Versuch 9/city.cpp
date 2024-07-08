#include "city.h"

/**
 * @brief Konstruktor für die City-Klasse.
 *
 * Initialisiert eine Stadt mit einem Namen und den Koordinaten (x, y).
 *
 * @param name Der Name der Stadt.
 * @param x Die x-Koordinate der Stadt.
 * @param y Die y-Koordinate der Stadt.
 */
City::City(QString name, int x, int y):
    name(name), x(x), y(y)
{

}
/**
 * @brief Destruktor für die City-Klasse.
 */
City::~City()
{

}
/**
 * @brief Zeichnet die Stadt auf der gegebenen QGraphicsScene.
 *
 * Diese Methode zeichnet einen Punkt und den Namen der Stadt auf der QGraphicsScene.
 *
 * @param scene Die QGraphicsScene, auf der die Stadt gezeichnet wird.
 */
void City::draw(QGraphicsScene &scene)
{
    QPen Pen;
    QString Stadt = this->name;
    Pen.setColor(Qt::white);
    Pen.setWidth(2);
    scene.addEllipse(x, y, 8, 8, Pen, QBrush(Qt::red, Qt::SolidPattern));

    QGraphicsTextItem* text = new QGraphicsTextItem;
    text->setPos(x, y);
    text->setPlainText(Stadt);
    scene.addItem(text);
}
/**
 * @brief Gibt den Namen der Stadt zurück.
 *
 * @return Der Name der Stadt als QString.
 */
QString City::getName()
{
    return name;
}
/**
 * @brief Gibt die x-Koordinate der Stadt zurück.
 *
 * @return Die x-Koordinate der Stadt.
 */
int City::getX()
{
    return x;
}
/**
 * @brief Gibt die y-Koordinate der Stadt zurück.
 *
 * @return Die y-Koordinate der Stadt.
 */
int City::getY()
{
    return y;
}
