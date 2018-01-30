#include "abteilung.h"
#include "angestellter.h"
#include "DatumsBerechnungen.h"
#include "stdafx.h"
#include "targetver.h"
#include <stdio.h>

void addDepartment(Abteilung department) 
{
	char Name, Adresse;
	int Abteilungsnummer;

	printf(" \n Herzlich Willkommen in der Sub- Routine zum Erstellen einer neuen Abteilung. \n");
	printf("Bitte geben Sie den Namen der neuen Abteilung ein.");
	scanf_s("%c", &department.Name);
	department.Name = Name;

	printf("\n Bitte geben Sie die Adresse der Abteilung ein.\n");
	scanf_s("%c", &department.Adresse);

	printf("\n Bitte geben Sie die Abteilungsnummer ein. \n");
	scanf_s("%c", &department.Abteilungsnummer);
	department.Angestellte.first = department.Angestellte.last = 0;
}

Angestellter createEmployee(Abteilung* department) 
{

	Angestellter* newEmployee = new Angestellter;
	
	printf("\n Herzlich Willkommen in der Sub- Routine zum Erstellen eines neuen Angestellten. \n");
	printf("\n Bitte geben Sie den Vornamen ein. \n");
	scanf_s("%c", &newEmployee->Vorname);
	printf("\n Bitte geben Sie den Nachnamen ein. \n");
	scanf_s("%c", &newEmployee->Nachname);
	printf("\n Bitte geben Sie nun die Personal Nummer des Angestellten ein. \n");
	scanf_s("%i", &newEmployee->persNummer);
	printf("\n Bitte geben Sie nun die Position des Angestellten ein. \n");
	scanf_s("%c", &newEmployee->Position);
	addEmployee(department, *newEmployee);
	printf("Bitte geben Sie das Geburtsdatum ein.");
	newEmployee->Geburtsdatum = Datumseingabe();
	printf("Bitte geben Sie das Einstellungsdatum ein.");
	newEmployee->Einstellungsdatum = Datumseingabe();
	printf("\n Bitte geben Sie das Gehalt ein.\n");
	scanf_s("%f", &newEmployee->Gehalt);
	newEmployee->succ = department->Angestellte.first;
	newEmployee->pred = 0;
	unsigned int index;
	
	return *newEmployee;
}

void addEmployee(Abteilung* department, Angestellter newEmployee) 
{
	newEmployee.succ = department->Angestellte.first;
	newEmployee.pred = 0;
	newEmployee.Abteilungszugehörigkeit = department;

	if (department->Angestellte.first == 0 )
	{
		department->Angestellte.last = &newEmployee;
	}
	else
	{
		department->Angestellte.first->pred = &newEmployee;
	}
	department->Angestellte.first = &newEmployee;
}

Angestellter* findEmployee(Abteilung* department, Angestellter* searchedEmployee)
{
	Angestellter* searched = department->Angestellte.first;
	int flag = 0;
	while (flag == 0)
	{
		if (searched == searchedEmployee)
		{
			flag = 1;
			return searched;
		}
		else
		{
			searched = searched->succ;
		}
	}
}

void deleteEmployee(Abteilung* department, Angestellter* kickedEmployee)
{
	Angestellter* doomed = findEmployee(department, kickedEmployee);
	doomed->pred->succ = doomed->succ;
	doomed->succ->pred = doomed->pred;
	delete doomed;
}

void moveEmployee(Abteilung* department, Abteilung* newdepartment, Angestellter* movedEmployee)
{
	Angestellter* movedEmployee = findEmployee(department, movedEmployee);
	movedEmployee->pred->succ = movedEmployee->succ;
	movedEmployee->succ->pred = movedEmployee->pred;
	addEmployee(newdepartment, *movedEmployee);
	delete movedEmployee;																//Ich weis nicht ob das so funktioniert, es muss der überflüssige Employee gelöscht werden
}

float sumOfSalary(Abteilung* department)
{
	Angestellter* Employee = department->Angestellte.first;
	float salarysum = 0;

	while (Employee != 0)
	{
		salarysum += Employee->Gehalt;
		Employee = Employee->succ;
	}

	return salarysum;
}

Angestellter* printLongestEmployment(Abteilung* department) // Hier durchaus colins lösung aus der letzten HA einfügen wollte es mal selber machen
{
	Angestellter* longestEmployment = department->Angestellte.first;
	Angestellter* Employee = department->Angestellte.first;
	while (Employee != 0)
	{
		if (DateAsInt(longestEmployment->Einstellungsdatum) - DateAsInt(Employee->Einstellungsdatum) < 0)
			longestEmployment = Employee;

		Employee = Employee->succ;
	}
	return longestEmployment;
}


Angestellter* printOldestEmployee(Abteilung* department) 
{
	Angestellter* oldestEmployee = department->Angestellte.first;
	Angestellter* Employee = department->Angestellte.first;
	while (Employee != 0)
	{
		if (DateAsInt(oldestEmployee->Geburtsdatum) - DateAsInt(Employee->Geburtsdatum) < 0)
			oldestEmployee = Employee;

		Employee = Employee->succ;
	}
	return oldestEmployee;
}

Angestellter* highestRankingEmployee(Abteilung* department) 
{
	Angestellter* highestRank = department->Angestellte.first;
	Angestellter* Employee = department->Angestellte.first;

	while (Employee != 0)
	{
		if (Employee->Position > highestRank->Position)
		{
			highestRank = Employee;
		}
		Employee = Employee->succ;
	}

	return highestRank;
}

void printDepartment(Abteilung* department) 
{
	int i = 1;
	Angestellter* Employee = department->Angestellte.first;
	printf("%c \n", department->Name);
	printf("%d \n", department->Abteilungsnummer);
	printf("%c \n", department->Adresse);
	while (Employee != 0)
	{
		printf("#%i %c, %c, %i \n", i, Employee->Nachname, Employee->Vorname, Employee->persNummer, Employee->Position);
		Employee = Employee->succ;
		i++;
	}
}

int AlterinJahren(Angestellter employee, int aktuellesJahr) //propably wrong
{
	int Alter = 0;
	Alter = aktuellesJahr - employee.Geburtsdatum.Jahr;

	return Alter;
}

int Betriebszugehörigkeit(Angestellter employee, int aktuellesJahr)
{
	int Jahre = 0;
	Jahre = aktuellesJahr - employee.Einstellungsdatum.Jahr;

	return Jahre;
}

