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

void addDepartment(DVL* department);
void addEmployee(DVL* department, Angestellter newEmployee);
void deleteEmployee(DVL* department, Angestellter* kickedEmployee);
void moveEmployee(DVL* department, DVL* newdepartment, Angestellter* movedEmployee);
Angestellter* findEmployee(DVL* department, Angestellter* searchedEmployee);
float sumOfSalary(DVL* department);
Angestellter printLongestEmployment(DVL* department);
void printOldestEmployee();
void highestRankingEmployee();
void printDepartment();
#endif // !abteilung_h
