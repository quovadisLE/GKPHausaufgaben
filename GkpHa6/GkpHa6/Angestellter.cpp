#include "angestellter.h"
#include "DatumsBerechnungen.h"
#include "abteilung.h"


Angestellter* findLongestEmployment(Abteilung* department)
{
	Angestellter* longestEmployment = department->Angestellte.first;
	Angestellter* Employee = department->Angestellte.first;
	while (Employee != nullptr)
	{
		if (DateAsInt(longestEmployment->Einstellungsdatum) - DateAsInt(Employee->Einstellungsdatum) < 0)
			longestEmployment = Employee;

		Employee = Employee->succ;
	}

	return longestEmployment;
}

Angestellter* findOldestEmployee(Abteilung* department)
{
	Angestellter* oldestEmployee = department->Angestellte.first;
	Angestellter* Employee = department->Angestellte.first;
	while (Employee != nullptr)
	{
		if (DateAsInt(oldestEmployee->Geburtsdatum) - DateAsInt(Employee->Geburtsdatum) < 0)
			oldestEmployee = Employee;

		Employee = Employee->succ;
	}

	return oldestEmployee;
}