// Observer_pattern.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "Observer.h"
#include "Subject.h"

using namespace std;

int main() {
	ActiveWorkers<Subject*>* activeSubjects = new ActiveWorkers<Subject*>();
	Subject* sub_1 = new Subject(1, activeSubjects);
	Subject* sub_2 = new Subject(2, activeSubjects);

	sub_1->add_1();
	sub_1->add_2();
	sub_1->add_2();	// will do nothing as 2nd object for sub_1 is already scheduled
	sub_2->add_3();

	activeSubjects->print();
	return 0;
}
