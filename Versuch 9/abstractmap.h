#ifndef ABSTRACTMAP
#define ABSTRACTMAP

//  Aendern Sie an dieser Datei nichts!
//  Entfernen Sie lediglich den Kommentar vor den Funktionen,
//  nachdem Sie diese in der Klasse Map implementiert haben.
//  Die Schnittstellen (Signaturen) der Funktionen
//  werden genau so gebraucht.

#include "city.h"
#include "street.h"

class AbstractMap
{
public:

    /// Virtual Destructor
    virtual ~AbstractMap();

    virtual void addCity(City*) = 0;

    virtual bool addStreet(Street*) = 0;

    virtual City* findCity(const QString cityName) const = 0;

    virtual QVector<Street*> getStreetList(const City* city) const = 0;

    virtual City* getOppositeCity(const Street* street, const City* city) const = 0;

    virtual double getLength(const Street* street) const = 0;
};

#endif // ABSTRACTMAP
