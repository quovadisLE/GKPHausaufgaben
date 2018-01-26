#include "abteilung.h"
#include "angestellter.h"
#include "stdafx.h"
#include "targetver.h"

void addDepartment(EVL* department) {
	department->first = department->last = 0;
}

void createEmployee() {
	Angestellter* newEmployee = new Angestellter;
	//definieren neuer Angestellter
}
void addEmployee(EVL* department, Angestellter newEmployee) {
	newEmployee.succ = department->first;
	
	if ( newEmployee.succ == 0) {
		department->last = &newEmployee;
	}
	department->first = &newEmployee;
}

void deleteEmployee(EVL* department, Angestellter kickedEmployee){
		
}