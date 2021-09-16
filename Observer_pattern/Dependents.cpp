#include <iostream>
#include "Observer.h"
#include "Subject.h"
#include "Dependents.h"

using namespace std;

Dependent::Dependent(int _sub_id, int _dependent_id, ActiveWorkers<Dependent*> *instance, Subject* _subject) {
	sub_id = _sub_id;
	dependent_id = _dependent_id;
	activeDependents = instance;
	subject = _subject;
	empty = true;
}

void Dependent::add() {
	if (empty) {
		listIt = activeDependents->notifyWork(this);
		empty = false;
	}
}

void Dependent::print() {
	cout << "subject id: " << sub_id << " Dependent id: " << dependent_id << endl;
}
