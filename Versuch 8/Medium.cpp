
/*!
 * Praktikum Informatik 1 
 * 
 *
 * @file Medium.cpp
 */
#include "Medium.h"

#include <string>
#include <iostream>

using namespace std;


/// @brief Statische Variable zur Vergabe von eindeutigen IDs.
unsigned int Medium::currentID = 1;


/*!
 * @brief Konstruktor der Klasse Medium.
 *
 * @param initTitel Der Titel des Mediums.
 */
Medium::Medium(std::string initTitel)
: titel(initTitel)
, status(false)
{
    ID = currentID++;
}

/*!
 * @brief Destruktor der Klasse Medium.
 */
Medium::~Medium(void)
{
}


/*!
 * @brief Gibt die Informationen des Mediums aus.
 *
 * @param outStream Der Ausgabestream, in den die Informationen geschrieben werden.
 */
void Medium::ausgabe(ostream& outStream) const
{
	outStream << "ID: " << ID << std::endl;
	outStream << "Titel: " << titel << std::endl;

    if (status)
    {
    	outStream << "Status : Das Medium ist seit dem " << datumAusgeliehen << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
    }
    else
    {
    	outStream << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
    }
}

/*!
 * @brief Verleiht das Medium an eine Person.
 *
 * @param person Die Person, an die das Medium verliehen wird.
 * @param ausleihdatum Das Datum, an dem das Medium ausgeliehen wird.
 * @return true, wenn das Medium erfolgreich verliehen wurde, false, wenn es bereits verliehen ist.
 */
bool Medium::ausleihen(Person person,Datum ausleihdatum)
{
    if (status)
    {
        std::cout << "Das Medium \"" << titel << "\" ist bereits verliehen!" << std::endl;
        return false;
    }
    else
    {
        status = true;
        personAusgeliehen = person;
        datumAusgeliehen = ausleihdatum;
        std::cout << "Das Medium \"" << titel << "\" wird an " << person.getName() << " verliehen." << std::endl;
        return true;
    }
}

/*!
 * @brief Gibt das Medium zurück.
 */
void Medium::zurueckgeben()
{
    if (status)
    {
        status = false;
        std::cout << "Das Medium \"" << titel << "\" wurde zurückgegeben." << std::endl;
    }
    else
    {
        std::cout << "Das Medium \"" << titel << "\" ist nicht verliehen!" << std::endl;
    }
}

/*!
 * @brief Gibt die ID des Mediums zurück.
 *
 * @return Die ID des Mediums.
 */
unsigned int Medium::getID()
{
    return ID;
}

/*!
 * @brief Gibt den Verleihstatus des Mediums zurück.
 *
 * @return true, wenn das Medium verliehen ist, false, wenn es verfügbar ist.
 */
bool Medium::getStatus()
{
    return status;
}

/*!
 * @brief Überladener Ausgabestream-Operator für die Klasse Medium.
 *
 * @param outStream Der Ausgabestream.
 * @param ausgabeMedium Das auszugebende Medium.
 * @return Der Ausgabestream.
 */
ostream& operator<<(ostream& outStream, const Medium& ausgabeMedium) {

	ausgabeMedium.ausgabe(outStream);
	return outStream;
}
