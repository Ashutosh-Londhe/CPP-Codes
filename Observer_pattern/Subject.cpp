#include "Subject.h"
#include "Observer.h"

Subject::Subject(int _sub_id, ActiveWorkers<Subject*>* instance) {
	sub_id = _sub_id;
	activeDependents = new ActiveWorkers<Dependent*>();
	activeSubjects = instance;

	obj_1 = new Dependent(sub_id, 1, activeDependents, this);
	obj_2 = new Dependent(sub_id, 2, activeDependents, this);
	obj_3 = new Dependent(sub_id, 3, activeDependents, this);

	empty = true;
}

void Subject::add_1() {
	obj_1->add();
}

void Subject::add_2() {
	obj_2->add();
}

void Subject::add_3() {
	obj_3->add();
}

void Subject::schedule_sub() {
	if (empty) {
		listIt = activeSubjects->notifyWork(this);
		empty = false;
	}
}

void Subject::print() {
	activeDependents->print();
	if (activeDependents->isEmpty()) {
		activeSubjects->notifyEmpty(listIt);
		empty = true;
	}
}
