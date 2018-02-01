#pragma once
#ifndef abteilung_h
#define abteilung_h
#include "angestellter.h"


typedef struct Abteilung
{
	std::string Name;
	std::string Adresse;
	int Abteilungsnummer;
	DVL Angestellte;
};

Abteilung* addDepartment();
void addEmployee(Abteilung* department, Angestellter* newEmployee);
Angestellter* createEmployee();
void deleteEmployee(Abteilung* department, Angestellter* kickedEmployee);
void moveEmployee(Abteilung* department, Abteilung* newdepartment, int persNummer);
Angestellter* findEmployeeWithPersonalNr(Abteilung* department, int PersonalNummer);
bool leiterVorhanden(Abteilung* department);
float sumOfSalary(Abteilung* department);
Angestellter* findLeiter(Abteilung* department);
void printDepartment(Abteilung* department);
void printEmployee(Angestellter* employee);

#endif // !abteilung_h
