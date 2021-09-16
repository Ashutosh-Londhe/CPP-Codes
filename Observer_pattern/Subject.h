#ifndef SUBJECT_H_INCLUDED
#define SUBJECT_H_INCLUDED

#include <iostream>
#include "Dependents.h"

class Subject {
private:
	int sub_id;
	bool empty;
	Dependent* obj_1;
	Dependent* obj_2;
	Dependent* obj_3;
	ActiveWorkers<Dependent*>* activeDependents;
	ActiveWorkers<Subject*>* activeSubjects;
	ActiveWorkers<Subject*>::TokenType listIt;
public:
	Subject* subject = nullptr;
	Subject(int _sub_id, ActiveWorkers<Subject*>* instance);
	void add_1();
	void add_2();
	void add_3();
	void schedule_sub();
	void print();
};

#endif // SUBJECT_H_INCLUDED
