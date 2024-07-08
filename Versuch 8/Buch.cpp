/**
 * Buch.cpp
 *
 *  Created on: 12 Jun 2024
 *      Author: baris
 */

#include "Buch.h"

using namespace std;
/**
 * @brief Konstruktor der Buch-Klasse.
 *
 * Erstellt ein neues Buch-Objekt mit dem gegebenen Titel und Autor.
 *
 * @param initTitel Der Titel des Buches.
 * @param initAutor Der Name des Autors des Buches.
 */
Buch::Buch(std::string initTitel, std::string initAutor):
	Medium(initTitel),
	autor(Person(initAutor, Datum()))
{

}
/**
 * @brief Gibt die Informationen des Buches aus.
 *
 * Überschreibt die ausgabe-Methode der Basisklasse Medium und gibt zusätzliche
 * Informationen über den Autor des Buches aus.
 *
 * @param outStream Der Ausgabestream, in den die Informationen geschrieben werden.
 */
void Buch::ausgabe(ostream& outStream) const
{

	Medium::ausgabe(outStream);

	outStream << "Name des Autors: " << this->autor.getName() << endl;

}
/**
 * @brief Destruktor der Buch-Klasse.
 *
 * Wird aufgerufen, wenn ein Buch-Objekt zerstört wird.
 */
Buch::~Buch()
{

}


