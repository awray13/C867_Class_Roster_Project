#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
#include "roster.h"

using namespace std;


Roster::Roster()
{
	this->rosterSize = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int rosterSize)
{
	this->rosterSize = rosterSize;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [rosterSize];
}


void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) 
{

}



// Removes students from the roster by student Id
void Roster::remove(string studentId)
{

	for (int i = 0; i <= lastIndex; ++i) 
	{
		if (classRosterArray[i] == nullptr) 
		{
			cout << "ERROR: Student with ID: " << studentId << " not found" << endl;
			break;
		}
		else if (studentId == classRosterArray[i]->getStudentId()) 
		{
			classRosterArray[i] = nullptr;
			cout << "Student removed" << endl;
		}
	}

}

void Roster::printAll()
{
	for (int i = 0; i <= this->lastIndex; i++) 
	{
		(this->classRosterArray)[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentId)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i) 
	{
		if (this->classRosterArray[i]->getStudentId() == studentId) 
		{
			found = true;
			int* days = classRosterArray[i]->getNumberOfDaysToCompleteCourse();
			cout << "Average number of days per course for student Id: " << studentId << " is " << (days[0] + days[1] + days[2]) / 3 << endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= lastIndex; ++i) 
	{
		string email = classRosterArray[i]->getEmailAddress();
		if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos)) 
		{
			cout << "The email for student: " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << " is not valid: " << email << endl;
		}
	}
}

void Roster::printByDegreeProgram(Degree degreeProgram)
{
	cout << "Student Roster by Degree: " << degreeTypeString[degreeProgram] << "\n";
	for (int i = 0; i <= lastIndex; ++i) 
	{
		if (this->classRosterArray[i]->getDegreeType() == degreeProgram) this->classRosterArray[i]->print();
	}
}

// Destroy 
Roster::~Roster()
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		delete this->classRosterArray[i];
	}
	delete this;
}