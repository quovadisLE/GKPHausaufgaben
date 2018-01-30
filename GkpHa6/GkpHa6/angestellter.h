#pragma once
#ifndef angestellter_h
#define angestellter_h

typedef struct ListeDerAngestellten
{
	char Vorname;
	char Nachname;
	int persNummer;
	Position Position;
	Abteilung* Abteilungszugehörigkeit; //now its right
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

enum Position
{
	Leiter = 3, Mitarbeiter = 2, Auszubildender = 1, Praktikant = 0
};

int AlterinJahren(Angestellter employee, int AktuellesJahr);
#endif // !angestellter_h
