#include "mapionrw.h"
/**
 * @brief Konstruktor der MapIoNrw-Klasse.
 *
 * Initialisiert eine neue Instanz der MapIoNrw-Klasse.
 */
MapIoNrw::MapIoNrw()
{
}
/**
 * @brief Destruktor der MapIoNrw-Klasse.
 *
 * Löscht eine Instanz der MapIoNrw-Klasse und gibt Ressourcen frei.
 */
MapIoNrw::~MapIoNrw()
{
}
/**
 * @brief Füllt die Karte mit Städten und Straßen in NRW.
 *
 * Diese Methode erstellt Städte und Straßen in Nordrhein-Westfalen und fügt sie einer gegebenen Karte hinzu.
 *
 * @param map Eine Referenz auf eine Instanz von AbstractMap, die gefüllt werden soll.
 */
void MapIoNrw::fillMap(AbstractMap &map)
{
    City* aachen = new City("Aachen", -100, 100);
    City* bonn = new City("Bonn", 0,200);
    City* koeln = new City("Köln", 0,0);
    City* duesseldorf = new City("Düsseldorf", 50,-100);

    Street* aachenKoeln = new Street(aachen, koeln);
    Street* bonnKoeln = new Street(bonn, koeln);
    Street* ddorfKoeln = new Street(duesseldorf, koeln);

    map.addCity(aachen);
    map.addCity(bonn);
    map.addCity(koeln);
    map.addCity(duesseldorf);


    map.addStreet(aachenKoeln);
    map.addStreet(bonnKoeln);
    map.addStreet(ddorfKoeln);
}
