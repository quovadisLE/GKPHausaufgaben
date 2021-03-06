// GkpHa6.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "abteilung.h"
#include "angestellter.h"
#include "DatumsBerechnungen.h"
#include <iostream>
#include <stdbool.h>
#include <string.h>
using namespace std;

int main()
{
	//Wahlvariablen
	bool flag = false;
	int choice, currentDepartment, currentEmployee, newdepartmentNr, persNr;
	int* pcurrentEmployee = &currentEmployee;
	
	char bummy;
	//Abteilungsvariablen
	Abteilung* departmentArray[255];
	int departmentCounter = 0; //DO NOT TOUCH

	//Gesuchter Angestellter
	Angestellter* searched = nullptr;

	Angestellter* unputEmployees[255];

	cout << "Herzlich Willkommen in Ihrem Abteilungsverwaltungs System. \n";

	while (flag != true)
	{
		cout << "Bitte Wählen Sie aus dem nachfolgenden Menue aus was Sie tuen moechten. \n";
		cout << "[1] Eine neue Abteilung erstellen. \n";
		cout << "[2] Einen neuen Angestellten zu der Abteilung hinzufuegen \n";
		cout << "[3] Einen Angestellten loeschen. \n";
		cout << "[4] Einen Angestellten zu einer anderen Abteilung zuordnen. \n";
		cout << "[5] Einen Angestellten anhand seiner Personal Nummer finden. \n";
		cout << "[6] Die Gehaltssumme einer Abteilung ausgeben. \n";
		cout << "[7] Den höchstrangigen Angestellten ausgeben \n";
		cout << "[8] Die gesamte Abteilung ausgeben. \n";
		cout << "[9] Den Dienstaeltesten Angestellten ausgeben. \n";
		cout << "[10] Den Aeltesten Angestellten ausgeben. \n";
		cout << "[0] Um das Programm zu beenden \n";
		
		cin >> choice;

		switch (choice)
		{
		case 1: departmentArray[departmentCounter] = addDepartment(); departmentCounter++;
			cin >> bummy;
			break;
		case 2: addEmployee(departmentArray[currentDepartment], unputEmployees[currentEmployee]);
			cin >> bummy;
			break;
		case 3: cout << "Welche Nummer soll ihr Angestellter haben. [0...255]  \n";
			cin >> currentEmployee;
			unputEmployees[currentEmployee] = createEmployee();
			cin >> bummy;
			break;
		case 4: cout << "Bitte geben Sie die Personal Nummer, die aktuelle Abteilung sowie die neue Abteilung ein. \n";
			cin >> persNr; cin >> currentDepartment; cin >> newdepartmentNr;
			moveEmployee(departmentArray[currentDepartment], departmentArray[newdepartmentNr], persNr);
			cin >> bummy;
			break;
		case 5: cout << "Bitte geben Sie die Personalnummer ein. \n";
			cin >> persNr;

			currentDepartment = 0;
			while (searched == nullptr)
			{
				if (currentDepartment > departmentCounter)
					break;
				searched = findEmployeeWithPersonalNr(departmentArray[currentDepartment], persNr);
				currentDepartment++;
			}

			if (searched != nullptr)
			{
				cout << "Wir haben den Angestellten in Abteilung " << currentDepartment << "gefunden. \n";
				cin >> bummy;
			}
			else
			{
				cout << "Leider konnten wir den Angestellten nicht finden.";
				cin >> bummy;
			}
			break;
		case 6: cout << "Von welcher Abteilung möchten Sie das gesamte Gehalt wissen.";
			cin >> currentDepartment;
			cout << "Das gesamte Gehalt der Abteilung beträgt: " << sumOfSalary(departmentArray[currentDepartment]) << "\n";
			cin >> bummy;
			break;
		case 7: cout << "Von welcher Abteilung möchten Sie den Leiter ermitteln. \n ";
			cin >> currentDepartment;
			searched = nullptr;
			searched = findLeiter(departmentArray[currentDepartment]);
			if (searched == nullptr)
			{
				cout << "Diese Abteilung hat noch keinen leitenden angestellten \n";
			cin >> bummy;
			}
			else
			{
				cout << "Der Leitende Angestellte ist: \n";
				printEmployee(searched);
				cin >> bummy;
			}
			break;
		case 8: cout << "Welche Abteilung möchten Sie ausgeben.";
			cin >> currentDepartment;
			printDepartment(departmentArray[currentDepartment]);
			cin >> bummy;
			break;
		case 9: cout << "Welche Abteilung. \n";
			cin >> currentDepartment;
			searched = findLongestEmployment(departmentArray[currentDepartment]);
			printEmployee(searched);
			cin >> bummy;
			break;
		case 10: cout << "Welche Abteilung. \n";
			cin >> currentDepartment;
			printEmployee(findOldestEmployee(departmentArray[currentDepartment]));
			cin >> bummy;
			break;
		case 0: flag == true; 
			break;
		}
	}

    return 0;
}