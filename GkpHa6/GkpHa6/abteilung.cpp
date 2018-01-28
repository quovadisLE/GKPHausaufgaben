#include "abteilung.h"
#include "angestellter.h"
#include "stdafx.h"
#include "targetver.h"

void addDepartment(DVL* department) {
	department->first = department->last = 0;
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

Angestellter printLongestEmployment(DVL* department)
{
	Angestellter* longestEmployment = department->first;
	Angestellter* Employee = department->first;
	while (Employee != 0)
	{
		
	}
}