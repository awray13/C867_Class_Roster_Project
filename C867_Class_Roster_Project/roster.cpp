#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
#include "roster.h"

using namespace std;


Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}


void Roster::add(string row)
{
	if (lastIndex < capacity) 
	{
		lastIndex++;
		int numOfDays[Student::numberOfDaysToCompleteCourseSize]; //A temporary array to hold number of days for each Student


		if (row.substr(row.length() - 8, 8) == "SOFTWARE") 
		{
			this->classRosterArray[lastIndex] = new SoftwareStudent();
			classRosterArray[lastIndex]->setDegreeType(SOFTWARE);
		}

		else if (row.substr(row.length() - 7, 7) == "NETWORK") 
		{
			this->classRosterArray[lastIndex] = new NetworkStudent();
			classRosterArray[lastIndex]->setDegreeType(NETWORK);
		}

		else if (row.substr(row.length() - 8, 8) == "SECURITY") 
		{
			this->classRosterArray[lastIndex] = new SecurityStudent();
			classRosterArray[lastIndex]->setDegreeType(SECURITY);
		}

		// Set studentId
		int rhs = studentData[lastIndex].find(",");
		classRosterArray[lastIndex]->setStudentId(studentData[lastIndex].substr(0, rhs));

		// Set firstName
		int lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

		// Set lastName
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

		// Set email
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setEmailAddress(studentData[lastIndex].substr(lhs, rhs - lhs));

		// Set age
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setAge(stoi(studentData[lastIndex].substr(lhs, rhs - lhs)));

		// Set number of days to complete courses
		// numberOfDaysToCompleteCourse[0]
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		numOfDays[0] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		// numberOfDaysToCompleteCourse[1]
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		numOfDays[1] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		// numberOfDaysToCompleteCourse[2]
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		numOfDays[2] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		classRosterArray[lastIndex]->setNumberOfDaysToCompleteCourse(numOfDays);
	}
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

void Roster::printDegree(Degree degreeProgram)
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
	for (int i = 0; i < numOfStudents; i++)
	{
		delete this->classRosterArray[i];
	}
	delete this;
}