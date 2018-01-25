#pragma once
#ifndef abteilung_h
#define abteilung_h
#include "angestellter.h"

typedef struct Abteilung
{
	char Name;
	char Adresse;
	int Abteilungsnummer;
	Angestellter Angestellte;
};

void newDepartmen();
void newEmployee();
void deleteEmployee();
void moveEmployee();
void sumOfSalary();
void printLongestEmployment();
void printOldestEmployee();
void highestRankingEmployee();
void printDepartment();
#endif // !abteilung_h
