
/**
 * DVD.cpp
 *
 *  Created on: 12 Jun 2024
 *      Author: baris
 */

#include "DVD.h"
/**
 * @brief Konstruktor der DVD-Klasse.
 *
 * Erstellt ein neues DVD-Objekt mit dem gegebenen Titel, Altersfreigabe und Genre.
 *
 * @param initTitel Der Titel der DVD.
 * @param initAltersfreigabe Die Altersfreigabe der DVD.
 * @param initGenre Das Genre der DVD.
 */
DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre):
	Medium(initTitel),
	altersfreigabe(initAltersfreigabe),
	genre(initGenre)
{

}
/**
 * @brief Versucht, die DVD an eine Person auszuleihen.
 *
 * Überprüft, ob die Person alt genug ist, um die DVD auszuleihen. Falls ja, wird die ausleihen-Methode
 * der Basisklasse Medium aufgerufen, andernfalls wird eine Fehlermeldung ausgegeben.
 *
 * @param person Die Person, die die DVD ausleihen möchte.
 * @param ausleihdatum Das Datum, an dem die DVD ausgeliehen werden soll.
 * @return true, wenn die DVD erfolgreich ausgeliehen wurde, andernfalls false.
 */
bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
	if ((ausleihdatum - person.getGeburtsdatum())  < (altersfreigabe * 12))
	{
		cout << "Die ausleihende Person ist nicht alt genug für diese DVD." << endl;
		return false;
	}
	else
	{
		return Medium::ausleihen(person, ausleihdatum);
	}
}
/**
 * @brief Gibt die Informationen der DVD aus.
 *
 * Überschreibt die ausgabe-Methode der Basisklasse Medium und gibt zusätzliche
 * Informationen über die Altersfreigabe und das Genre der DVD aus.
 *
 * @param outStream Der Ausgabestream, in den die Informationen geschrieben werden.
 */
void DVD::ausgabe(ostream& outStream) const
{

	Medium::ausgabe(outStream);
	outStream << "FSK: ab " << altersfreigabe << " Jahre" << endl;
	outStream << "Genre: " << genre << endl;
}
/**
 * @brief Destruktor der DVD-Klasse.
 *
 * Wird aufgerufen, wenn ein DVD-Objekt zerstört wird.
 */
DVD::~DVD()
{
}


