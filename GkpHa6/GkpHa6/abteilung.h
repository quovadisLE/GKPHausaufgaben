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

Abteilung* addDepartment();
void addEmployee(Abteilung* department, Angestellter newEmployee);
void deleteEmployee(Abteilung* department, Angestellter* kickedEmployee);
void moveEmployee(Abteilung* department, Abteilung* newdepartment, Angestellter* movedEmployee);
Angestellter* findEmployeeWithPersonalNr(Abteilung* department, int PersonalNummer);
bool leiterVorhanden(Abteilung* department);
float sumOfSalary(Abteilung* department);
Angestellter* highestRankingEmployee(Abteilung* department);
void printDepartment(Abteilung* department);


#endif // !abteilung_h
