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

void addDepartment(EVL* department);
void addEmployee(EVL* department, Angestellter newEmployee);
void deleteEmployee(EVL* department, Angestellter kickedEmployee);
void moveEmployee();
void sumOfSalary();
void printLongestEmployment();
void printOldestEmployee();
void highestRankingEmployee();
void printDepartment();
#endif // !abteilung_h
