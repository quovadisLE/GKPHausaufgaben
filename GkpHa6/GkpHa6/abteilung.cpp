#include "abteilung.h"
#include "angestellter.h"
#include "stdafx.h"
#include "targetver.h"
#include <stdio.h>

void addDepartment(Abteilung department) 
{
	//eingeben
	department.Angestellte.first = department.Angestellte.last = 0;
}

Angestellter createEmployee() 
{
	Angestellter* newEmployee = new Angestellter;
	//definieren neuer Angestellter
	addEmployee(newEmployee->Abteilungszugehörigkeit, *newEmployee);
	return *newEmployee;
}
void addEmployee(DVL* department, Angestellter newEmployee) 
{
	newEmployee.succ = department->first;
	newEmployee.pred = 0;

	if (department->first == 0 ) 
	{
		department->last = &newEmployee;
	}
	else
	{
		department->first->pred = &newEmployee;
	}
	department->first = &newEmployee;
}

Angestellter* findEmployee(DVL* department, Angestellter* searchedEmployee)
{
	Angestellter* searched = department->first;
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

void deleteEmployee(DVL* department, Angestellter* kickedEmployee)
{
	Angestellter* doomed = findEmployee(department, kickedEmployee);
	doomed->pred->succ = doomed->succ;
	doomed->succ->pred = doomed->pred;
	delete doomed;
}

void moveEmployee(DVL* department, DVL* newdepartment, Angestellter* movedEmployee)
{
	Angestellter* movedEmployee = findEmployee(department, movedEmployee);
	movedEmployee->pred->succ = movedEmployee->succ;
	movedEmployee->succ->pred = movedEmployee->pred;
	addEmployee(newdepartment, *movedEmployee);
	delete movedEmployee;																//Ich weis nicht ob das so funktioniert, es muss der überflüssige Employee gelöscht werden
}

float sumOfSalary(DVL* department)
{
	Angestellter* Employee = department->first;
	float salarysum = 0;

	while (Employee != 0)
	{
		salarysum += Employee->Gehalt;
		Employee = Employee->succ;
	}

	return salarysum;
}

Angestellter* printLongestEmployment(DVL* department) // Hier durchaus colins lösung aus der letzten HA einfügen wollte es mal selber machen
{
	Angestellter* longestEmployment = department->first;
	Angestellter* Employee = department->first;
	while (Employee != department->last)
	{
		if (longestEmployment->Einstellungsdatum.Jahr - Employee->Einstellungsdatum.Jahr < 0)
		{
			longestEmployment = Employee;
		}
		else if(longestEmployment->Einstellungsdatum.Jahr - Employee->Einstellungsdatum.Jahr == 0)
		{
			if (longestEmployment->Einstellungsdatum.Monat - Employee->Einstellungsdatum.Monat < 0)
			{
				longestEmployment = Employee;
			}
			else if (longestEmployment->Einstellungsdatum.Monat - Employee->Einstellungsdatum.Monat == 0)
			{
				if (longestEmployment->Einstellungsdatum.Monat - Employee->Einstellungsdatum.Monat < 0)
				{
					longestEmployment = Employee;
				}
				else if (longestEmployment->Einstellungsdatum.Tag - Employee->Einstellungsdatum.Tag < 0)
				{
					longestEmployment = Employee;
				}

			}
		}
		Employee = Employee->succ;
	}
	return longestEmployment;
}


Angestellter* printOldestEmployee(DVL* department) // Hier durchaus colins lösung aus der letzten HA einfügen wollte es mal selber machen
{
	Angestellter* oldestEmployee = department->first;
	Angestellter* Employee = department->first;
	while (Employee != department->last)
	{
		if (oldestEmployee->Geburtsdatum.Jahr - Employee->Geburtsdatum.Jahr < 0)
		{
			oldestEmployee = Employee;
		}
		else if (oldestEmployee->Geburtsdatum.Jahr - Employee->Geburtsdatum.Jahr == 0)
		{
			if (oldestEmployee->Geburtsdatum.Monat - Employee->Geburtsdatum.Monat < 0)
			{
				oldestEmployee = Employee;
			}
			else if (oldestEmployee->Geburtsdatum.Monat - Employee->Geburtsdatum.Monat == 0)
			{
				if (oldestEmployee->Geburtsdatum.Monat - Employee->Geburtsdatum.Monat < 0)
				{
					oldestEmployee = Employee;
				}
				else if (oldestEmployee->Geburtsdatum.Tag - Employee->Geburtsdatum.Tag < 0)
				{
					oldestEmployee = Employee;
				}

			}
		}
		Employee = Employee->succ;
	}
	return oldestEmployee;
}

Angestellter* highestRankingEmployee(DVL* department) 
{
	Angestellter* highestRank = department->first;
	Angestellter* Employee = department->first;

	while (Employee != department->last)
	{
		if (Employee->Position > highestRank->Position)
		{
			highestRank = Employee;
		}
		Employee = Employee->succ;
	}

	return highestRank;
}

void printDepartment(Abteilung department) 
{
	Angestellter* Employee = department.Angestellte.first;
	printf("%c \n", department.Name);
	printf("%d \n", department.Abteilungsnummer);
	printf("%c \n", department.Adresse);
	while (Employee != department.Angestellte.last)
	{
		//print the fuck out
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