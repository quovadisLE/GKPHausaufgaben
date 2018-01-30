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
void addEmployee(Abteilung* department, Angestellter newEmployee);
void deleteEmployee(Abteilung* department, Angestellter* kickedEmployee);
void moveEmployee(Abteilung* department, Abteilung* newdepartment, Angestellter* movedEmployee);
Angestellter* findEmployee(Abteilung* department, Angestellter* searchedEmployee);
float sumOfSalary(Abteilung* department);
Angestellter* highestRankingEmployee(Abteilung* department);
void printDepartment(Abteilung* department);

#endif // !abteilung_h
