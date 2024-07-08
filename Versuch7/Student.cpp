
//////////////////////////////////////////////////////////////////////////////
/// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "Student.h"

/**
 * @brief Konstruktor, der einen neuen Studenten mit allen Werten erstellt
 *
 * @param matNr Matrikelnummer
 * @param name Name
 * @param geburtstag Geburtstag
 * @param adresse Adresse
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief Standardkonstruktor, der einen leeren Studenten erstellt
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief Destruktor für die Student-Klasse.
 *
 * Dieser Destruktor ist verantwortlich für das Aufräumen
 * aller Ressourcen, die das Student-Objekt während seiner Lebensdauer
 * möglicherweise erworben hat. Da es in der aktuellen Implementierung
 * keine dynamisch zugewiesenen Ressourcen gibt, ist der Destruktor leer.
 */
Student::~Student()
{}

/**
 * @brief Gibt die Matrikelnummer des Studenten zurueck
 *
 * @return Matrikelnummer
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Gibt den Namen des Studenten zurueck
 *
 * @return Name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Gibt den Geburtstag des Studenten zurueck
 *
 * @return Geburtstag
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Gibt die Adresse des Studenten zurueck
 *
 * @return Adresse
 */
std::string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief Gibt die Daten eines Studenten auf einem Ausgabestream aus.
 *
 * Diese Methode überprüft, ob der gegebene Ausgabestream ein ofstream ist.
 * Wenn ja, werden die Daten des Studenten in ein Dateiformat geschrieben.
 * Andernfalls werden die Daten in einem lesbaren Format auf die Konsole oder einen anderen Ausgabestream ausgegeben.
 *
 * @param outStream Der Ausgabestream, in den die Daten geschrieben werden sollen.
 */
void Student::ausgabe(ostream& outStream) const
{
	auto* ofs = dynamic_cast<std::ofstream*>(&outStream);
	if (ofs)
	{
        outStream << matNr << std::endl;
        outStream << name << std::endl;
        outStream << geburtstag << std::endl;
        outStream << adresse;
	}
	else
	{
	    outStream << name << ", MatNr. " << matNr << ", geb. am "
	              << geburtstag << ", wohnhaft in " << adresse
	              << std::endl;
	}

}


/**
 * @brief Überladener Gleichheitsoperator.
 *
 * Vergleicht zwei Studenten anhand ihrer Matrikelnummern.
 *
 * @param otherStudent Der Student, mit dem verglichen werden soll.
 * @return true, wenn die Matrikelnummern gleich sind, andernfalls false.
 */
bool Student::operator==(const Student& otherStudent) const {
	if (this->matNr == otherStudent.getMatNr()) return true;
	else return false;
}

/**
 * @brief Überladener Kleiner-als-Operator.
 *
 * Vergleicht die Matrikelnummer zweier Studenten.
 *
 * @param otherStudent Der Student, mit dem verglichen werden soll.
 * @return true, wenn die Matrikelnummer dieses Studenten kleiner ist, andernfalls false.
 */
bool Student::operator<(const Student& otherStudent) const {
	if (this->matNr < otherStudent.getMatNr()) return true;
	else return false;
}

/**
 * @brief Überladener Größer-als-Operator.
 *
 * Vergleicht die Matrikelnummer zweier Studenten.
 *
 * @param otherStudent Der Student, mit dem verglichen werden soll.
 * @return true, wenn die Matrikelnummer dieses Studenten größer ist, andernfalls false.
 */
bool Student::operator>(const Student& otherStudent) const {
	if (this->matNr > otherStudent.getMatNr()) return true;
	else return false;
}

/**
 * @brief Überladener Kleiner-gleich-Operator.
 *
 * Vergleicht die Matrikelnummer zweier Studenten.
 *
 * @param otherStudent Der Student, mit dem verglichen werden soll.
 * @return true, wenn die Matrikelnummer dieses Studenten kleiner oder gleich ist, andernfalls false.
 */
bool Student::operator<=(const Student& otherStudent) const {
	if (this->matNr <= otherStudent.getMatNr()) return true;
	else return false;
}

/**
 * @brief Überladener Größer-gleich-Operator.
 *
 * Vergleicht die Matrikelnummer zweier Studenten.
 *
 * @param otherStudent Der Student, mit dem verglichen werden soll.
 * @return true, wenn die Matrikelnummer dieses Studenten größer oder gleich ist, andernfalls false.
 */
bool Student::operator>=(const Student& otherStudent) const {
	if (this->matNr >= otherStudent.getMatNr()) return true;
	else return false;
}

/**
 * @brief Überladener Ausgabeoperator.
 *
 * Gibt die Daten eines Studenten auf einem Ausgabestream aus.
 *
 * @param outStream Der Ausgabestream.
 * @param student Der Student, dessen Daten ausgegeben werden sollen.
 * @return Der Ausgabestream.
 */
ostream& operator<<(ostream& outStream, const Student& student) {
	student.ausgabe(outStream);

	return outStream;
}

