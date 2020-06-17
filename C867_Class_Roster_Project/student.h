#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;


// Student class
class Student 
{
	
protected:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* numberOfDaysToCompleteCourse;
	Degree degreeType;


// Public members have access to all classes
public:
	const static int numberOfDaysToCompleteCourseSize = 3;
	// Constructors
	Student();
	Student(string newId, string newFirstName, string newLastName, string newEmail, int newAge, int newNumDaysToComplete[], Degree newDegreeType);

	// Accessors
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getNumberOfDaysToCompleteCourse();
	virtual Degree getDegreeType() = 0; 

	// Mutators
	void setStudentId(string newId);
	void setFirstName(string newFirstName);
	void setLastName(string newLastName);
	void setEmailAddress(string newEmail);
	void setAge(int newAge);
	void setNumberOfDaysToCompleteCourse(int newNumDaysToComplete[]);
	virtual void setDegreeType(Degree d) = 0;
	virtual void print() = 0;

	// Destructor
	~Student();
};

#endif

