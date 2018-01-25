#pragma once
#ifndef angestellter_h
#define angestellter_h

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
	Angestellter* succ;
}Angestellter;

struct EVL {
	Angestellter* first;
	Angestellter* last;
};

typedef struct Datum
{
	unsigned short Tag;
	unsigned short Monat;
	int Jahr;
};



#endif // !angestellter_h
