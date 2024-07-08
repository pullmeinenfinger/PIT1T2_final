
//////////////////////////////////////////////////////////////////////////////
/// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

/**
 * @brief Die Student-Klasse repräsentiert einen Studenten mit Matrikelnummer, Name, Geburtstag und Adresse.
 */
class Student
{
public:

    /**
     * @brief Standardkonstruktor, der einen leeren Studenten erstellt.
     */
    Student();


    /**
         * @brief Destruktor für die Student-Klasse.
    */
    ~Student();


    /**
     * @brief Konstruktor, der einen neuen Studenten mit allen Werten erstellt.
     *
     * @param matNr Matrikelnummer
     * @param name Name
     * @param geburtstag Geburtstag
     * @param adresse Adresse
     */
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);


    /**
     * @brief Gibt die Matrikelnummer des Studenten zurück.
     *
     * @return Matrikelnummer
     */
    unsigned int getMatNr() const;


    /**
     * @brief Gibt den Namen des Studenten zurück.
     *
     * @return Name
     */
    std::string getName() const;


    /**
     * @brief Gibt den Geburtstag des Studenten zurück.
     *
     * @return Geburtstag
     */
    std::string getGeburtstag() const;


    /**
     * @brief Gibt die Adresse des Studenten zurück.
     *
     * @return Adresse
     */
    std::string getAdresse() const;


    /**
     * @brief Gibt alle Daten des Studenten in einer Zeile aus.
     */
    void ausgabe() const;


private:
    unsigned int matNr; /// Matrikelnummer des Studenten
    std::string name; /// Name des Studenten
    std::string geburtstag; /// Geburtstag des Studenten
    std::string adresse; /// Adresse des Studenten
};

#endif
