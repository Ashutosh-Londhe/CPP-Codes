#ifndef DEPENDENTS_H_INCLUDED
#define DEPENDENTS_H_INCLUDED

#include "Observer.h"
#include "Subject.h"
class Subject;

class Dependent {
private:
	bool empty;
	int sub_id, dependent_id;
	ActiveWorkers<Dependent*> *activeDependents;
	ActiveWorkers<Dependent*>::TokenType listIt;
public:
	Subject *subject;
	Dependent(int _sub_id, int _depenedent_id, ActiveWorkers<Dependent*> *instance, Subject* _subject);
	void add();
	void print();
};

#endif // DEPENDENTS_H_INCLUDED
