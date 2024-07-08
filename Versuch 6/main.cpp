/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch 6: STL
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Student.h"

using namespace std;


/**
 * Funktion zum Überprüfen, ob ein Student existiert
 *
 * @param studentenListe, ein Vector von Studierenden
 * @param matNr, der matNr der Studierenden, welche überprüft werden soll
 *
 * @return boolean für das Ergebnis der Überprüfung
 */
bool studentExists(vector<Student>* studentenListe, unsigned int matNr) {

	for (const Student& i : *studentenListe) {
		if (i.getMatNr() == matNr) return true;
	}
	return false;
}


/**
 * @brief Main-Funktion, die die Verwaltung der Studenten-Datenbank durchführt.
 *
 * Diese Funktion ermöglicht es, Studenten-Daten aus einer Datei einzulesen, zu bearbeiten,
 * anzuzeigen und in eine Datei zu speichern. Das Hauptmenü bietet mehrere Optionen zur
 * Verwaltung der Datenbank.
 *
 * @return int Rückgabewert 0 bei normalem Programmende, 1 bei Fehler.
 */

int main()
{
    vector<Student> studentenListe; ///init Datenbank als Liste
    vector<Student>::iterator it;
    Student student; ///Member erstellen

    ///Variablen
    char abfrage;
	string dateiname, name, geburtsdatum, adresse;
	unsigned int matNr;



    cout << "Wollen Sie Daten aus einer Datei einlesen? (j)/(n) ";
    cin >> abfrage;
    cin.ignore(1, '\n');


    if (abfrage == 'j') {

    	cout << "Geben sie nun Bitte den Dateinamen an (DEFAULT: 'studierende.txt'): ";
        getline(cin, dateiname);    /// ganze Zeile einlesen inklusive aller Leerzeichen
        if (dateiname.empty()) dateiname = "studierende.txt";

        ifstream eingabe(dateiname);

        if (!eingabe)
        {
        	cout << " Fehler beim Lesen der Datei!";
            studentenListe.clear();
        	exit(1) ;
        }


		while (!eingabe.eof())
        {
			eingabe >> matNr;
        	eingabe.ignore(1, '\n'); /// wegen >> Whitespaces einnimmt
        	getline(eingabe , name);
        	getline(eingabe , geburtsdatum);
        	getline(eingabe , adresse);

        	student = Student(matNr, name, geburtsdatum, adresse); ///Konstrukt
			student.ausgabe();

			studentenListe.push_back(student);///Datenbank
        }


    };

    do
    {
        cout << "\nMenü:" << endl
                  << "-----------------------------" << endl
                  << "(1): Datenelement hinten hinzufügen" << endl
                  << "(2): Datenelement vorne entfernen" << endl
                  << "(3): Datenbank ausgeben" << endl
                  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << endl
                  << "(5): Datenelement löschen" << endl
                  << "(6): Datenelement vorne hinzufügen" << endl
                  << "(7): Datenelement hinten entfernen" << endl
                  << "(8): Daten aus einer Datei einlesen" << endl
                  << "(9): Daten in eine Datei abspeichern" << endl
                  << "(0): Beenden" << endl;

        cin >> abfrage;
        cin.ignore(10, '\n');

        switch (abfrage)
        {

            /// Datenelement hinten hinzufügen
            /// wird als leztze hinzugefügt
            case '1':
                {
                    unsigned int matNr = 0;
                    string name = "";
                    string geburtsdatum = "";
                    string adresse = "";

                    cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                    getline(cin, name);    /// ganze Zeile einlesen inklusive aller Leerzeichen
                    cout << "Geburtsdatum: ";
                    getline(cin, geburtsdatum);
                    cout << "Adresse: ";
                    getline(cin, adresse);
                    cout << "Matrikelnummer: ";
                    cin >> matNr;
                    cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtsdatum, adresse);

                    studentenListe.push_back(student);
                }
                break;


            /// Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        it = studentenListe.begin();
                        cout << "Der folgende Student ist geloescht worden:" << endl;
                        it->ausgabe();
                        studentenListe.erase(it);
                    }
                    else
                    {
                        cout << "Die Liste ist schon leer!\n";
                    }
                }
                break;


            /// Datenbank vorwärts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
                    cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << endl;
                    for (vector<Student>::iterator it1 = studentenListe.begin() ; it1 != studentenListe.end(); ++it1)
                        it1->ausgabe();
                }
                else
                {
                    cout << "Die Liste ist leer!\n\n";
                }
                break;


            /// Datenbank rückwärts ausgeben
            case '4':
                if(!studentenListe.empty())
                {
                    cout << "Inhalt der Liste in rücklaufender Reihenfolge:" << endl;
                    for (vector<Student>::reverse_iterator it1 = studentenListe.rbegin() ; it1 != studentenListe.rend(); ++it1)
						it1->ausgabe();
                }
                else
                {
                    cout << "Die Liste ist leer!\n\n";
                }
                break;


            /// Datenelement löschen
            case '5':
            	{
            		unsigned int zahl = 0;
            		unsigned int untreffZahl = 0;
            		unsigned int matNrLoeschen;

					if(studentenListe.empty())
					{
						cout << "Die Liste ist leer!\n\n" << endl;
						break;
					}

					cout << "Bitte geben sie die Matrikelnummer an: " << endl;
					cin >> matNrLoeschen;

					for(vector<Student>::iterator it1 = studentenListe.begin(); it1 != studentenListe.end(); it1++)
					{
						zahl++;
						if (matNrLoeschen == it1->getMatNr())
						{
							cout << "Der folgende Student wurde geloescht:\n" << endl;
							it1->ausgabe();
							studentenListe.erase(it1);
							///kein break; , falls duplizierte Student
						}
						else
						{
							untreffZahl++;
							continue;
						}
					}

					if(untreffZahl == zahl)
					{
						cout << "Der Student wurde nicht gefunden...\n\n";
					}
					else
					{
						for(vector<Student>::iterator it1 = studentenListe.begin(); it1 != studentenListe.end(); it1++)
						{
							zahl = 0;
							untreffZahl = 0;
							zahl++;
							if (matNrLoeschen == it1->getMatNr())
							{
								cout << "\nDer Student konnte nicht gelöscht werden:\n" << endl;
								abfrage = '0';
								break;

							}
							else
							{
								untreffZahl++;
								continue;
							}
						}

						if(untreffZahl == zahl)
						{
							cout << "\nDer Student wurde erfolgreich gelöscht.\n\n";
						}
					}
            	}
                break;

            /// Datenelement vorne hinzufügen
            case '6':
            	{
            		unsigned int matNr = 0;
					string name = "";
					string geburtstag = "";
					string adresse = "";
					it = studentenListe.begin();

					cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
					getline(cin, name);    /// ganze Zeile einlesen inklusive aller Leerzeichen

					cout << "Geburtsdatum: ";
					getline(cin, geburtstag);

					cout << "Adresse: ";
					getline(cin, adresse);

					cout << "Matrikelnummer: ";
					cin >> matNr;
					cin.ignore(10, '\n');

					student = Student(matNr, name, geburtstag, adresse);

					studentenListe.insert(it, student);
            	}

                break;

                /// Datenelement hinten entfernen
            case '7':
                {
                	if(!studentenListe.empty())
                    	{
                            cout << "Der folgende Student ist gelöscht worden:" << endl;
                            (studentenListe.end()-1)->ausgabe();
                            studentenListe.pop_back();
                        }
                        else
                        {
                            cout << "Die Liste ist schon leer!\n";
                        }
                }
                break;

            /// Daten aus einer Datei einlesen
			case '8':
				{
					bool mergeData = false;
					bool uberschrift = false;
					if(!studentenListe.empty())
					{
						cout << "Es sind bereits Daten vorhanden. Sollen diese:" << endl
								<< "(1) Gelöscht werden" << endl
								<< "(2) In eine Datei gespeichert, und dann lokal gelöscht (Default Wahl an keine Angabe)" << endl
								<< "(3) Mit den einzulesenden Dateien gemerged werden (hierbei haben die vorhandenen Daten Priorität)" << endl
								<< "(4) Mit den einzulesenden Dateien überschreibt werden (schreibt über vorhandenen Daten)" << endl
								<< "(0) Programm Beenden" << endl << endl;

						cin >> abfrage;
						cin.ignore(10, '\n');

						switch (abfrage)
						{
							case '0':
					            studentenListe.clear();
					        	exit(1) ;

							case '1':
								studentenListe.clear();
								mergeData = false;
								uberschrift = false;
								break;

							case '3':

								mergeData = true;
								uberschrift = false;

								break;

							case '4':

								mergeData = true;
								uberschrift = true;

								break;

							default:
								mergeData = false;
								uberschrift = false;
								string dateiName1;
								cout << "Bitte geben Sie Dateiname (default an keine Angabe: erstStudierende.txt): ";
								getline(cin,dateiName1);
								if (dateiName1 == "")
								{
									dateiName1 = "erstStudierende.txt";
								}
								ifstream neuOaltDatei(dateiName1);
								ofstream ausgabe;
								if (!neuOaltDatei.good())
								{
									neuOaltDatei.close();
									ausgabe.open(dateiName1);
								}
								else
								{
									neuOaltDatei.close();
									ausgabe.open(dateiName1, ios::app);
									ausgabe << endl;

								}
								if (!ausgabe)
								{
									cout << " Fehler beim Öffnen der Datei !";
						            studentenListe.clear();
									exit(1) ;
								}
								for(auto it = studentenListe.begin(); it != studentenListe.end(); ++it)
								{
									const Student& i = *it;
									ausgabe << i.getMatNr() << endl;
									ausgabe << i.getName() << endl;
									ausgabe << i.getGeburtstag() << endl;
									ausgabe << i.getAdresse();


									if (next(it) != studentenListe.end())
									{
									    	ausgabe << endl;
									}


								}

								ausgabe.close();
								studentenListe.clear();
								cout << "Erfolgreich!\n";
								break;
						}

					}

					cout << "\nGeben sie nun Bitte den eingelesene Dateinamen an. (ENTER für 'studierende.txt)'";

					string dateiname;
					getline(cin, dateiname);    /// ganze Zeile einlesen inklusive aller Leerzeichen
					if (dateiname.empty()) dateiname = "studierende.txt";

					ifstream eingabe(dateiname);

					if (!eingabe)
					{
						cout << " Fehler beim Öffnen der Datei !";
			            studentenListe.clear();
			        	exit(1) ;
					}

					unsigned int matNr;
					string name;
					string geburtsdatum;
					string adresse;

					while (!eingabe.eof())
					{
						eingabe >> matNr;
						eingabe.ignore(1, '\n');
						getline(eingabe , name);
						getline(eingabe , geburtsdatum);
						getline(eingabe , adresse);



						student = Student(matNr, name, geburtsdatum, adresse);

						if (uberschrift==false && mergeData && studentExists(&studentenListe, matNr))
						{
							cout << "Folgender Student wurde nicht eingefügt, da die Matrikelnummer bereits existiert: " << endl;
							student.ausgabe();
							cout << "wird vernachlässt.\n";

						}
						else if (mergeData && uberschrift && studentExists(&studentenListe, matNr))
						{
							cout << "Matrikelnummer folgendes Students bereits existiert: " << endl;
							student.ausgabe();
							for(vector<Student>::iterator it1 = studentenListe.begin(); it1 != studentenListe.end(); it1++)
							{

								if (matNr == it1->getMatNr())
								{
									studentenListe.erase(it1);
									studentenListe.insert(it1, student);
									///kein break; , falls duplizierte Student
								}
							}
							cout << "wird über vorhandenen Daten schreibt";
						}
						else if (mergeData ==false && uberschrift==false && studentExists(&studentenListe, matNr))
						{
							cout << "Folgender Student wurde nicht eingefügt, da die Matrikelnummer bereits existiert: " << endl;
							student.ausgabe();
							cout << "wird vernachlässt.\n";
						}
						else
						{
							studentenListe.push_back(student);
							cout << "Folgender Student wurde eingefügt: " << endl;
							student.ausgabe();
						}


					}

				}
				break;

            /// Daten in eine Datei speichern
			case '9':
				{
					if(studentenListe.empty())
					{
						cout << "Es sind keine Daten vorhanden, die abgespeichert werden könnten." << endl;

						break;
					}

					cout << "Geben sie nun Bitte den Dateinamen an. (ENTER für 'neuStudierende.txt)'";
					string dateiname;

					getline(cin, dateiname);    /// ganze Zeile einlesen inklusive aller Leerzeichen
					if (dateiname.empty()) dateiname = "neuStudierende.txt";

					ofstream ausgabe(dateiname, ios::trunc);

					if (!ausgabe)
					{
						cout << " Fehler beim Öffnen der Datei !";
			            studentenListe.clear();
						exit(1) ;
					}

					for(auto it = studentenListe.begin(); it != studentenListe.end(); ++it)
					{
						const Student& i = *it;
						ausgabe << i.getMatNr() << endl;
						ausgabe << i.getName() << endl;
						ausgabe << i.getGeburtstag() << endl;
						ausgabe << i.getAdresse();


						if (next(it) != studentenListe.end())
						{
						    	ausgabe << endl;
						}


					}

					ausgabe.close();
					cout << "Erfolgreich!\n";
				}
				break;

            case '0':
                cout << "Das Programm wird nun beendet";
                break;

            default :
                cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');
    studentenListe.clear();
    return 0;
}
