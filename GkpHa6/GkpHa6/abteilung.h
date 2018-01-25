#pragma once
#ifndef abteilung_h
#define abteilung_h
typedef struct Abteilung
{
	char Name;
	char Adresse;
	int Abteilungsnummer;
	List Angestellte;
};

typedef struct ListeDerAngestellten
{
	char Vorname;
	char Nachname;
	int persNummer;
	enum Position
	{
		Leiter, Mitarbeiter, Auszubildender, Praktikant
	};
	//abteilung
	Datum Geburtsdatum;
	Datum Einstellungsdatum;
	float Gehalt;
}List;

typedef struct Datum
{
	unsigned short Tag;
	unsigned short Monat;
	int Jahr;
};




#endif // !abteilung_h
