/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch 7: Überladung
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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
	Student tempStudent(matNr, "","","");
	for (const Student& i : *studentenListe) {
		if (i == tempStudent) return true; /// statt .getMatNr() Operator Überladung
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
    Student student; ///Standartkonstrukt - leer Student

    ///Variablen
    char abfrage;
	string dateiname, name, geburtsdatum, adresse;
	unsigned int matNr;
	int menu;


    cout << "Wollen Sie Daten aus einer Datei einlesen? (j)/(n) ";
    cin >> abfrage;
    cin.ignore(10, '\n');


    if (abfrage == 'j') {

    	cout << "Geben sie nun Bitte den Dateinamen an. (ENTER für 'studierende.txt)'";
        getline(cin, dateiname);    /// ganze Zeile einlesen inklusive aller Leerzeichen
        if (dateiname.empty()) dateiname = "studierende.txt";

        ifstream eingabe(dateiname);

        if (!eingabe)
        {
        	cout << " Fehler beim Oeffnen der Datei !";
            studentenListe.clear();
        	exit(1) ;
        }

		while (!eingabe.eof())
        {
			eingabe >> matNr;
        	eingabe.ignore(1, '\n');
        	getline(eingabe , name);
        	getline(eingabe , geburtsdatum);
        	getline(eingabe , adresse);

        	student = Student(matNr, name, geburtsdatum, adresse);
			cout << student; /// Überladen

			studentenListe.push_back(student);
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
				  << "(10): Datenbank sortiert ausgeben" << endl
				  << "(11): Datenbank permanent sortieren und ausgeben" << endl
                  << "(0): Beenden" << endl;
        cin >> menu;
        cin.ignore(10, '\n');

        switch (menu)
        {
			/// Datenelement hinten hinzufügen
			/// wird als leztze hinzugefügt
			case 1:
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
			case 2:
				{
					if(!studentenListe.empty())
					{
						it = studentenListe.begin();
						cout << "Der folgende Student ist geloescht worden:" << endl;
						cout << *it << endl; /// Operator Überladung
						studentenListe.erase(it);
					}
					else
					{
						cout << "Die Liste ist schon leer!\n";
					}
				}
				break;


			/// Datenbank vorwärts ausgeben
			case 3:
				if(!studentenListe.empty())
				{
					cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << endl;
					for (vector<Student>::iterator it1 = studentenListe.begin() ; it1 != studentenListe.end(); ++it1)
						cout << *it1;/// Operator Überladung
				}
				else
				{
					cout << "Die Liste ist leer!\n\n";
				}
				break;


			/// Datenbank rückwärts ausgeben
			case 4:
				if(!studentenListe.empty())
				{
					cout << "Inhalt der Liste in rücklaufender Reihenfolge:" << endl;
					for (vector<Student>::reverse_iterator it1 = studentenListe.rbegin() ; it1 != studentenListe.rend(); ++it1)
						cout << *it1;/// Operator Überladung
				}
				else
				{
					cout << "Die Liste ist leer!\n\n";
				}
				break;


			/// Datenelement löschen!!
			case 5:
				{
					unsigned int matNrLoeschen;


					if(studentenListe.empty())
					{
						cout << "Die Liste ist leer!\n\n" << endl;
						break;
					}

					cout << "Bitte geben sie die Matrikelnummer an: " << endl;
					cin >> matNrLoeschen;
					Student tempStudent(matNrLoeschen,"","","");
					it = find(studentenListe.begin(),studentenListe.end(), tempStudent);
					if (it != studentenListe.end())
					{
						cout << "Studierende gefunden und wird gelöscht: " << *it;
						studentenListe.erase(it);
						it = find(studentenListe.begin(),studentenListe.end(), tempStudent);
						if (it == studentenListe.end())
						{
							cout << "Studierende erfolgreich gelöscht.\n ";
							for (vector<Student>::iterator it1 = studentenListe.begin() ; it1 != studentenListe.end(); ++it1)
								cout << *it1;/// Operator Überladung
						}
						else
						{
							cout << "Studierende konnte nicht gelöscht.\n";
						}
					}
					else
					{
						cout << "Studierende wurde nicht gefunden.\n";
					}
					///Überprüfen


				}
				break;

			/// Datenelement vorne hinzufügen
			case 6:
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
			case 7:
				{
					if(!studentenListe.empty())
						{
							it = (studentenListe.end()-1);
							cout << "Der folgende Student ist geloescht worden:" << endl;
							cout << *it <<endl; /// Operator Überladung
							studentenListe.pop_back();
						}
						else
						{
							cout << "Die Liste ist schon leer!\n";
						}
				}
				break;

			/// Daten aus einer Datei einlesen
			case 8:
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
							default:
							{
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
									ausgabe << i; /// Operator Überladung
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
						}

					}

					cout << "Geben sie nun Bitte den Dateinamen an. (ENTER für 'studierende.txt)'";

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
							cout << student;/// Operator Überladung
							cout << "wird vernachlässt.\n";

						}
						else if (mergeData && uberschrift && studentExists(&studentenListe, matNr))
						{
							cout << "Matrikelnummer folgendes Students bereits existiert: " << endl;
							cout << student;/// Operator Überladung
							for(vector<Student>::iterator it1 = studentenListe.begin(); it1 != studentenListe.end(); it1++)
							{

								if (*it1 == student) ///operator Überladen
								{
									studentenListe.erase(it1);
									studentenListe.insert(it1, student);
									///kein break; , falls duplizierte Student
								}
							}
							cout << "wird über vorhandenen Daten schreibt."<<endl<<endl;

						}
						else if (mergeData ==false && uberschrift==false && studentExists(&studentenListe, matNr))
						{
							cout << "Folgender Student wurde nicht eingefügt, da die Matrikelnummer bereits existiert: " << endl;
							cout << student <<endl;/// Operator Überladung
							cout << "wird vernachlässt.\n";
						}
						else
						{
							studentenListe.push_back(student);
							cout << "Folgender Student wurde eingefügt: " << endl;
							cout << student <<endl;/// Operator Überladung
						}


					}

				}
				break;

			/// Daten in eine Datei speichern
			case 9:
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
						ausgabe << i; /// Operator Überladung
						if (next(it) != studentenListe.end())
						{
						    	ausgabe << endl;
						}

					}

					ausgabe.close();
					studentenListe.clear();
					cout << "Erfolgreich!\n";
				}
				break;

			///sortierte Ausgabe
			case 10:
			{
				vector<Student> tempList;
				for(auto it4 = studentenListe.begin(); it4 != studentenListe.end(); ++it4)
				{
					tempList.push_back(*it4);
				}
				sort(tempList.begin(),tempList.end());
				for(auto it2 = tempList.begin(); it2 != tempList.end(); ++it2)
				{
					cout<< *it2;
				}
				break;
			}
			case 11:
			{
				sort(studentenListe.begin(),studentenListe.end());
				for(auto it3 = studentenListe.begin(); it3 != studentenListe.end(); ++it3)
				{
					cout<< *it3;
				}
				break;
			}
			case 0:
				cout << "Das Programm wird nun beendet";
				break;

			default :
				cout << "Falsche Eingabe, bitte nochmal";
				break;
		}
	}
    while (menu != 0);
    studentenListe.clear();
    return 0;
}
