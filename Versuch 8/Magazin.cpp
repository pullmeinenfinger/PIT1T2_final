/**
 * Magazin.cpp
 *
 *  Created on: 12 Jun 2024
 *      Author: baris
 */

#include "Magazin.h"

using namespace std;
/**
 * @brief Konstruktor der Magazin-Klasse.
 *
 * Erstellt ein neues Magazin-Objekt mit dem gegebenen Titel, Erscheinungsdatum und Sparte.
 *
 * @param initTitel Der Titel des Magazins.
 * @param initDatumAusgabe Das Erscheinungsdatum des Magazins.
 * @param initSparte Die Sparte des Magazins.
 */
Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte):
	Medium(initTitel),
	erscheinungsdatum(initDatumAusgabe),
	sparte(initSparte)
{

}
/**
 * @brief Gibt die Informationen des Magazins aus.
 *
 * Überschreibt die ausgabe-Methode der Basisklasse Medium und gibt zusätzliche
 * Informationen über das Erscheinungsdatum und die Sparte des Magazins aus.
 *
 * @param outStream Der Ausgabestream, in den die Informationen geschrieben werden.
 */
void Magazin::ausgabe(ostream& outStream) const
{
	/**
ID: 1
Titel: c’t - Magazin für Computertechnik
Status: Medium ist zurzeit nicht verliehen.
Ausgabe: 01/04/2018
Sparte: Computerzeitschrift
	 */
	Medium::ausgabe(outStream);
	outStream << "Ausgabe: " << this->erscheinungsdatum << endl;
	outStream << "Sparte: " << this->sparte << endl;
}
/**
 * @brief Versucht, das Magazin an eine Person auszuleihen.
 *
 * Überprüft, ob das Erscheinungsdatum des Magazins in der Zukunft liegt. Falls ja, wird das Ausleihen
 * verweigert, andernfalls wird die ausleihen-Methode der Basisklasse Medium aufgerufen.
 *
 * @param person Die Person, die das Magazin ausleihen möchte.
 * @param ausleihdatum Das Datum, an dem das Magazin ausgeliehen werden soll.
 * @return true, wenn das Magazin erfolgreich ausgeliehen wurde, andernfalls false.
 */
bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
	if ((ausleihdatum - erscheinungsdatum)  <= 0)
	{
		cout << "Die neueste Ausgabe von Magazinen dürfen nicht ausgeliehen werden." << endl;
		return false;
	}
	else
	{
		return Medium::ausleihen(person, ausleihdatum);
	}
}

/**
 * @brief Destruktor der Magazin-Klasse.
 *
 * Wird aufgerufen, wenn ein Magazin-Objekt zerstört wird.
 */
Magazin::~Magazin()
{}


