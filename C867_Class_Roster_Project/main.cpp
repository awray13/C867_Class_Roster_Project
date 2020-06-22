#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
#include "roster.h"

using namespace std;

// MAIN: Function responsible for running program
int main()
{
	// My info
	cout << "SCRIPTING AND PROGRAMMING - APPLICATIONS - C867" << endl;
	cout << "C++" << endl;
	cout << "#001252298" << endl;
	cout << "Ashton Wray" << endl;
	cout << "================================================" << endl << endl;

	Roster* classRoster = new Roster(numberOfStudents);

	for (int i = 0; i < numberOfStudents; i++) 
	{
		classRoster->add(studentData[i], ",");
	}


	cout << "Roster" << endl;
	classRoster->printAll();
	cout << endl;

	cout << "Invalid Emails" << endl;
	classRoster->printInvalidEmails();
	cout << endl;

	cout << "Average days per class for each student" << endl;
	for (int i = 0; i < numberOfStudents; ++i) 
	{
		classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getStudentId());
	}
	cout << endl;


	classRoster->printDegree(SOFTWARE);
	cout << endl;
	classRoster->remove("A3");
	cout << endl;
	classRoster->remove("A3");
	cout << endl;



	system("pause");
	return 0;
}