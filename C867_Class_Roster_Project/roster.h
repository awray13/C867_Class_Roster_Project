#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <list>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

const int numberOfStudents = 5;

const string studentData[] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Ashton,Wray,awray11@my.wgu.edu,33,40,30,32,SOFTWARE"
};

class Roster 
{
	public:
		int lastIndex;
		int rosterSize;

		Roster();
		Roster(int rosterSize);

		void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree);
		void printAll();
		void remove(string studentId);
		void printAverageDaysInCourse(string studentId);
		void printInvalidEmails();
		void printByDegreeProgram(Degree degreeProgram);

		Student** classRosterArray;

		

		~Roster();
};

#endif

