#pragma once
#ifndef abteilung_h
#define abteilung_h
#include "angestellter.h"

typedef struct Abteilung
{
	char Name;
	char Adresse;
	int Abteilungsnummer;
	DVL Angestellte;
};

void addDepartment(Abteilung department);
void addEmployee(DVL* department, Angestellter newEmployee);
void deleteEmployee(DVL* department, Angestellter* kickedEmployee);
void moveEmployee(DVL* department, DVL* newdepartment, Angestellter* movedEmployee);
Angestellter* findEmployee(DVL* department, Angestellter* searchedEmployee);
float sumOfSalary(DVL* department);
Angestellter* printLongestEmployment(DVL* department);
Angestellter* printOldestEmployee(DVL* department);
Angestellter* highestRankingEmployee(DVL* department);
void printDepartment(Abteilung department);
#endif // !abteilung_h
