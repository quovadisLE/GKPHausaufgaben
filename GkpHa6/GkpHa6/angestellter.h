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
	DVL* Abteilungszugehörigkeit;
	Datum Geburtsdatum;
	Datum Einstellungsdatum;
	float Gehalt;
	Angestellter* succ;
	Angestellter* pred;
	unsigned int index;
}Angestellter;

struct DVL {
	Angestellter* first;
	Angestellter* last;
};

typedef struct Datum
{
	unsigned short Tag;
	unsigned short Monat;
	int Jahr;
};

typedef struct Abteilung 
{
	DVL Mitglieder;
};


#endif // !angestellter_h
