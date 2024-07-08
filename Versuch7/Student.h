
//////////////////////////////////////////////////////////////////////////////
/// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <vector>

using namespace std;
/**
 * @brief Repräsentiert einen Studenten.
 *
 * Die Klasse Student speichert Informationen über einen Studenten, einschließlich
 * Matrikelnummer, Name, Geburtstag und Adresse. Sie bietet Methoden zum Zugriff auf
 * diese Informationen und zum Ausgeben der Daten.
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
      * @param matNr Matrikelnummer.
      * @param name Name.
      * @param geburtstag Geburtstag.
      * @param adresse Adresse.
      */
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);
    /**
      * @brief Gibt die Matrikelnummer des Studenten zurück.
      *
      * @return Matrikelnummer.
      */
    unsigned int getMatNr() const;
    /**
     * @brief Gibt den Namen des Studenten zurück.
     *
     * @return Name.
     */
    std::string getName() const;
    /**
     * @brief Gibt den Geburtstag des Studenten zurück.
     *
     * @return Geburtstag.
     */
    std::string getGeburtstag() const;
    /**
     * @brief Gibt die Adresse des Studenten zurück.
     *
     * @return Adresse.
     */
    std::string getAdresse() const;
    /**
     * @brief Gibt die Daten des Studenten auf die Standardausgabe aus.
     */
    void ausgabe() const { ausgabe(cout); } ;
    /**
       * @brief Gibt die Daten des Studenten auf einem Ausgabestream aus.
       *
       * @param outStream Der Ausgabestream, in den die Daten geschrieben werden sollen.
       */
    void ausgabe(ostream& outStream) const;
    /**
     * @brief Überladener Gleichheitsoperator.
     *
     * Vergleicht zwei Studenten anhand ihrer Matrikelnummern.
     *
     * @param otherStudent Der Student, mit dem verglichen werden soll.
     * @return true, wenn die Matrikelnummern gleich sind, andernfalls false.
     */
    bool operator==(const Student& otherStudent) const;
    /**
      * @brief Überladener Größer-als-Operator.
      *
      * Vergleicht die Matrikelnummer zweier Studenten.
      *
      * @param otherStudent Der Student, mit dem verglichen werden soll.
      * @return true, wenn die Matrikelnummer dieses Studenten größer ist, andernfalls false.
      */
    bool operator>(const Student& otherStudent) const;
    /**
         * @brief Überladener Kleiner-als-Operator.
         *
         * Vergleicht die Matrikelnummer zweier Studenten.
         *
         * @param otherStudent Der Student, mit dem verglichen werden soll.
         * @return true, wenn die Matrikelnummer dieses Studenten kleiner ist, andernfalls false.
         */
    bool operator<(const Student& otherStudent) const;
    /**
     * @brief Überladener Größer-gleich-Operator.
     *
     * Vergleicht die Matrikelnummer zweier Studenten.
     *
     * @param otherStudent Der Student, mit dem verglichen werden soll.
     * @return true, wenn die Matrikelnummer dieses Studenten größer oder gleich ist, andernfalls false.
     */
    bool operator>=(const Student& otherStudent) const;
    /**
     * @brief Überladener Kleiner-gleich-Operator.
     *
     * Vergleicht die Matrikelnummer zweier Studenten.
     *
     * @param otherStudent Der Student, mit dem verglichen werden soll.
     * @return true, wenn die Matrikelnummer dieses Studenten kleiner oder gleich ist, andernfalls false.
     */
    bool operator<=(const Student& otherStudent) const;
private:
    unsigned int matNr;      /// Matrikelnummer des Studenten.
    std::string name;        /// Name des Studenten.
    std::string geburtstag;  /// Geburtstag des Studenten.
    std::string adresse;     /// Adresse des Studenten.
};

/**
 * @brief Überladener Ausgabeoperator.
 *
 * Gibt die Daten eines Studenten auf einem Ausgabestream aus.
 *
 * @param outStream Der Ausgabestream.
 * @param student Der Student, dessen Daten ausgegeben werden sollen.
 * @return Der Ausgabestream.
 */
ostream& operator<<(ostream& outStream, const Student& student);


#endif
