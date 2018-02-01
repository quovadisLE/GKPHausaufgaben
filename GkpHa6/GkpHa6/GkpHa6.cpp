// GkpHa6.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "abteilung.h"
#include "angestellter.h"
#include "DatumsBerechnungen.h"
#include <iostream>
#include <stdbool.h>
#include <string>


int main()
{
	bool flag = false;
	
	std::cout << "Herzlich Willkommen in Ihrem Abteilungsverwaltungs System. \n";

	while (flag != true)
	{
		std::cout << "Bitte Wählen Sie aus dem nachfolgenden Menue aus was Sie tuen moechten. \n";
		std::cout << "[1] Eine neue Abteilung erstellen. \n";
		std::cout << "[2] Einen neuen Angestellten zu der Abteilung hinzufuegen \n";
		std::cout << "[3] Einen Angestellten loeschen. \n";
		std::cout << "[4] Einen Angestellten zu einer anderen Abteilung zuordnen. \n";
		std::cout << "[5] Einen Angestellten anhand seiner Personal Nummer finden. \n";
		std::cout << "[6] Die Gehaltssumme einer Abteilung ausgeben. \n";
		std::cout << "[7] Den höchstrangigen Angestellten ausgeben \n";
		std::cout << "[8] Die gesamte Abteilung ausgeben. \n";
		std::cout << "[9] Den Dienstaeltesten Angestellten ausgeben. \n";
		std::cout << "[10] Den Aeltesten Angestellten ausgeben. \n";
		std::cout << "[e] Um das Programm zu beenden \n";
	}

    return 0;
}

Abteilung* addDepartment();
void addEmployee(Abteilung* department, Angestellter newEmployee);
void deleteEmployee(Abteilung* department, Angestellter* kickedEmployee);
void moveEmployee(Abteilung* department, Abteilung* newdepartment, Angestellter* movedEmployee);
Angestellter* findEmployeeWithPersonalNr(Abteilung* department, int PersonalNummer);
bool leiterVorhanden(Abteilung* department);
float sumOfSalary(Abteilung* department);
Angestellter* highestRankingEmployee(Abteilung* department);
void printDepartment(Abteilung* department);