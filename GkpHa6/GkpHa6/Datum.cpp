#include "DatumsBerechnungen.h"
#include <stdio.h>

Datum Datumseingabe()
{
	Datum* Date = new Datum;
	printf("\n Bitte geben Sie den Tag ein.\n");
	scanf_s("%i", &Date->Tag);
	printf("\n Bitte geben Sie den Monat ein. \n");
	scanf_s("%i", &Date->Monat);
	printf("\n Bitte geben Sie das Jahr ein. \n");
	scanf_s("%i", &Date->Jahr);

	return *Date;
}

int DateAsInt(Datum date)
{
	int x = 0;

	switch (date.Monat) {
	case 1: x = date.Tag;
		break;
	case 2: x = 31 + date.Tag;
		break;
	case 3: x = 59 + date.Tag;
		break;
	case 4: x = 90 + date.Tag;
		break;
	case 5: x = 120 + date.Tag;
		break;
	case 6: x = 151 + date.Tag;
		break;
	case 7: x = 181 + date.Tag;
		break;
	case 8: x = 212 + date.Tag;
		break;
	case 9: x = 243 + date.Tag;
		break;
	case 10: x = 273 + date.Tag;
		break;
	case 11: x = 304 + date.Tag;
		break;
	case 12: x = 334 + date.Tag;
	}

	if (date.Jahr % 4 == 0) {   //Jahre im Schaltjahr haben einen Tag mehr als regulaere Jahre, deshalb wird 1 addiert
		++x;
	}

	x += date.Jahr * 365;

	return x;
}