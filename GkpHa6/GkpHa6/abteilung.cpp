#include "abteilung.h"
#include "angestellter.h"
#include "DatumsBerechnungen.h"
#include "stdafx.h"
#include "targetver.h"
#include <iostream>
#include <stdbool.h>

Abteilung* addDepartment() 
{

	Abteilung* department = new Abteilung;
	char Name, Adresse;
	int Abteilungsnummer;

	std::cout << "\n Herzlich Willkommen in der Sub- Routine zum Erstellen einer neuen Abteilung. \n";
	std::cout << "Bitte geben Sie den Namen der neuen Abteilung ein.";
	std::cin >> department->Name;
	department->Name = Name;

	std::cout <<("\n Bitte geben Sie die Adresse der Abteilung ein.\n");
	std::cin >> department->Adresse;

	std::cout <<("\n Bitte geben Sie die Abteilungsnummer ein. \n");
	std::cin >> department->Abteilungsnummer;
	department->Angestellte.first = department->Angestellte.last = 0;

	return department;
}

Angestellter* createEmployee(Abteilung* department) 
{

	Angestellter* newEmployee = new Angestellter;
	char dummy;

	std::cout <<("\n Herzlich Willkommen in der Sub- Routine zum Erstellen eines neuen Angestellten. \n");
	
	std::cout <<("\nBitte geben Sie den Vornamen ein. \n ");
	std::cin >> newEmployee->Vorname;
	
	std::cout <<("\nBitte geben Sie den Nachnamen ein. \n");
	std::cin >> newEmployee->Nachname;
	
	std::cout <<("\nBitte geben Sie nun die Personal Nummer des Angestellten ein. \n");
	std::cin >> newEmployee->persNummer;
	
	std::cout <<("\nBitte geben Sie nun die Position des Angestellten ein. \n");
	std::cout << "Beachten Sie das nur die Folgenden Möglichkeiten wählbar sind: \n Praktikant, Auszubildender, Mitarbeiter, Leiter";
	std::cin >> dummy;
	switch (dummy)
	{
	case Praktikant : newEmployee->Position = Praktikant;
		break;

	case Mitarbeiter: newEmployee->Position = Mitarbeiter;
		break;

	case Leiter: if (leiterVorhanden(newEmployee->Abteilungszugehörigkeit) == true) //Check ob ein Leiter vorhanden ist.
	{
		std::cout << "Es ist schon ein Abteilungsleitervorhanden vorhanden.";
		return nullptr;
		break;
	}
		newEmployee->Position = Leiter; 
		break;

	case Auszubildender: newEmployee->Position = Auszubildender;
		break;
	}
	
	addEmployee(department, *newEmployee);
	
	std::cout <<("\nBitte geben Sie das Geburtsdatum ein.\n");
	newEmployee->Geburtsdatum = Datumseingabe();
	
	std::cout <<("\nBitte geben Sie das Einstellungsdatum ein.\n");
	newEmployee->Einstellungsdatum = Datumseingabe();
	
	std::cout <<("\n Bitte geben Sie das Gehalt ein.\n");
	std::cin >> newEmployee->Gehalt;
	
	newEmployee->succ = department->Angestellte.first;
	newEmployee->pred = 0;

	unsigned int index;
	
	return newEmployee;
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

Angestellter* findEmployeeWithPersonalNr(Abteilung* department, int PersonalNummer)
{
	Angestellter* searched = department->Angestellte.first;
	int flag = 0;
	while (searched != 0)
	{
		if (searched->persNummer == PersonalNummer)
		{
			flag = 1;
			return searched;
		}
		else
		{
			searched = searched->succ;
		}
	}

	return nullptr;
}

bool leiterVorhanden(Abteilung* department)
{
	Angestellter* istLeiter = department->Angestellte.first;
	
	while (istLeiter != 0)
	{
		if (istLeiter->Position == Leiter)
			return true;
	}

	return false;
}

void deleteEmployee(Abteilung* department, Angestellter* kickedEmployee)
{
	Angestellter* doomed = findEmployeeWithPersonalNr(department, kickedEmployee->persNummer);
	doomed->pred->succ = doomed->succ;
	doomed->succ->pred = doomed->pred;
	
	delete doomed;
}

void moveEmployee(Abteilung* department, Abteilung* newdepartment, Angestellter* movedEmployee)
{
	Angestellter* movedEmployee = findEmployeeWithPersonalNr(department, movedEmployee->persNummer);
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

Angestellter* printLongestEmployment(Abteilung* department) 
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
	std::cout <<("%c \n", department->Name);
	std::cout <<("%d \n", department->Abteilungsnummer);
	std::cout <<("%c \n", department->Adresse);
	while (Employee != 0)
	{
		std::cout << "# " << i;
		printEmployee(Employee);
		Employee = Employee->succ;
		i++;
	}
}

void printEmployee(Angestellter* employee)
{
	std::cout << " " << employee->Nachname << " " << employee->Vorname << " " << employee->persNummer << " " << employee->Position << " \n ";
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

