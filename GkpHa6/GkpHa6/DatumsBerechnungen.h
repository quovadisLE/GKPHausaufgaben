#pragma once
#ifndef datumsBerechnungen_h
#define datumsBerechnungen_h

typedef struct Datum
{
	unsigned short Tag;
	unsigned short Monat;
	int Jahr;
};

int DateAsInt(Datum date);
Datum Datumseingabe();

#endif // !datum_h
