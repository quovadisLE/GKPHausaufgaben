#include "abteilung.h"
#include "angestellter.h"
#include "DatumsBerechnungen.h"
#include "stdafx.h"
#include "targetver.h"
#include <iostream>
#include <stdbool.h>
using namespace std;

Abteilung* addDepartment() 
{

	Abteilung* department = new Abteilung;
	char Name, Adresse;
	int Abteilungsnummer;

	cout << "\n Herzlich Willkommen in der Sub- Routine zum Erstellen einer neuen Abteilung. \n";
	cout << "Bitte geben Sie den Namen der neuen Abteilung ein.";
	cin >> department->Name;
	department->Name = Name;

	cout <<("\n Bitte geben Sie die Adresse der Abteilung ein.\n");
	cin >> department->Adresse;

	cout <<("\n Bitte geben Sie die Abteilungsnummer ein. \n");
	cin >> department->Abteilungsnummer;
	department->Angestellte.first = department->Angestellte.last = 0;

	return department;
}

Angestellter* createEmployee() 
{
	Angestellter* newEmployee = new Angestellter;
	char dummy;

	cout <<("\n Herzlich Willkommen in der Sub- Routine zum Erstellen eines neuen Angestellten. \n");
	
	cout <<("\nBitte geben Sie den Vornamen ein. \n ");
	cin >> newEmployee->Vorname;
	
	cout <<("\nBitte geben Sie den Nachnamen ein. \n");
	cin >> newEmployee->Nachname;
	
	cout <<("\nBitte geben Sie nun die Personal Nummer des Angestellten ein. \n");
	cin >> newEmployee->persNummer;
	
	cout <<("\nBitte geben Sie nun die Position des Angestellten ein. \n");
	cout << "Beachten Sie das nur die Folgenden Möglichkeiten wählbar sind: \n Praktikant, Auszubildender, Mitarbeiter, Leiter";
	cin >> dummy;
	switch (dummy)
	{
	case Praktikant : newEmployee->Position = Praktikant;
		break;

	case Mitarbeiter: newEmployee->Position = Mitarbeiter;
		break;

	case Leiter: newEmployee->Position = Leiter; 
		break;

	case Auszubildender: newEmployee->Position = Auszubildender;
		break;
	}
	
	cout <<("\nBitte geben Sie das Geburtsdatum ein.\n");
	newEmployee->Geburtsdatum = Datumseingabe();
	
	cout <<("\nBitte geben Sie das Einstellungsdatum ein.\n");
	newEmployee->Einstellungsdatum = Datumseingabe();
	
	cout <<("\n Bitte geben Sie das Gehalt ein.\n");
	cin >> newEmployee->Gehalt;

	return newEmployee;
}

void addEmployee(Abteilung* department, Angestellter* newEmployee) 
{
	if (newEmployee->Position == Leiter)
	{
		if (leiterVorhanden(newEmployee->Abteilungszugehörigkeit) == true)
		{
			cout << "Es ist schon ein Abteilungsleitervorhanden vorhanden.";
			return;
		}
	}

	newEmployee->succ = department->Angestellte.first;
	newEmployee->pred = 0;
	newEmployee->Abteilungszugehörigkeit = department;

	if (department->Angestellte.first == 0 )
	{
		department->Angestellte.last = newEmployee;
	}
	else
	{
		department->Angestellte.first->pred = newEmployee;
	}
	department->Angestellte.first = newEmployee;
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

void moveEmployee(Abteilung* department, Abteilung* newdepartment, int persNummer)
{
	Angestellter* movedEmployee = findEmployeeWithPersonalNr(department, persNummer);
	movedEmployee->pred->succ = movedEmployee->succ;
	movedEmployee->succ->pred = movedEmployee->pred;
	addEmployee(newdepartment, movedEmployee);
	
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



Angestellter* findLeiter(Abteilung* department) 
{
	Angestellter* highestRank = department->Angestellte.first;
	Angestellter* Employee = department->Angestellte.first;

	while (Employee->Position != Leiter)
	{
		if (Employee->Position == Leiter)
			highestRank = Employee;

		Employee = Employee->succ;
		
		if (Employee == nullptr)
			break;
		
	}

	return highestRank;
}

void printDepartment(Abteilung* department) 
{
	int i = 1;
	Angestellter* Employee = department->Angestellte.first;
	cout <<("%c \n", department->Name);
	cout <<("%d \n", department->Abteilungsnummer);
	cout <<("%c \n", department->Adresse);
	while (Employee != 0)
	{
		cout << "# " << i;
		printEmployee(Employee);
		Employee = Employee->succ;
		i++;
	}
}

void printEmployee(Angestellter* employee)
{
	cout << " " << employee->Nachname << " " << employee->Vorname << " " << employee->persNummer << " " << employee->Position << " \n ";
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

void printDepartmentSorted(Abteilung *department)
{
	Angestellter* Employee = department->Angestellte.first;
	cout << ("%c \n", department->Name);
	cout << ("%d \n", department->Abteilungsnummer);
	cout << ("%c \n", department->Adresse);
}