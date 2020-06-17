#include<iostream>
#include<iomanip>
#include "student.h"
#include "degree.h"
using namespace std;

// Implementation of Student Class
// Default contructor
Student::Student() { 
	{
		this->studentId = "";
		this->firstName = "";
		this->lastName = "";
		this->emailAddress = "";
		this->age = 0;
		// create a NEW array dynamically - MUST because it's VIRTUAL
		this->numberOfDaysToCompleteCourse = new int[numberOfDaysToCompleteCourseSize]; // create new array and use destrctor to dispose of it
		for (int i = 0; i < numberOfDaysToCompleteCourseSize; i++) this->numberOfDaysToCompleteCourse[i] = 0;

	}
}

Student::Student(string newId, string newFirstName, string newLastName, string newEmail, int newAge, int newNumDaysToComplete[], Degree newDegreeType) {
	this->studentId = newId;
	this->firstName = newFirstName;
	this->lastName = newLastName;
	this->emailAddress = newEmail;
	this->age = newAge;
	
	// New instance of Array
	this->numberOfDaysToCompleteCourse = new int[numberOfDaysToCompleteCourseSize];

	// Loop through Array
	for (int i = 0; i < 3; i++) this->numberOfDaysToCompleteCourse[i] = newNumDaysToComplete[i];
}

// Accessors
string Student::getStudentId() 
{
	return studentId;
}

string Student::getFirstName() 
{
	return firstName;
}

string Student::getLastName() 
{
	return lastName;
}

string Student::getEmailAddress() 
{
	return emailAddress;
}

int Student::getAge() 
{
	return age;
}

int* Student::getNumberOfDaysToCompleteCourse() 
{
	return numberOfDaysToCompleteCourse;
}

// Mutators
void Student::setStudentId(string newId)
{
	this->studentId = newId;
}
void Student::setFirstName(string newFirstName)
{
	this->firstName = newFirstName;
}
void Student::setLastName(string newLastName)
{
	this->lastName = newLastName;
}
void Student::setEmailAddress(string newEmail)
{
	this->emailAddress = newEmail;
}
void Student::setAge(int newAge)
{
	this->age = newAge;
}
void Student::setNumberOfDaysToCompleteCourse(int newNumDaysToComplete[])
{
	if (this->numberOfDaysToCompleteCourse != nullptr)
	{
		delete[] this->numberOfDaysToCompleteCourse;
		this->numberOfDaysToCompleteCourse = nullptr;
	}

	this->numberOfDaysToCompleteCourse = new int[numberOfDaysToCompleteCourseSize];
	for (int i = 0; i < 3; i++)
		this->numberOfDaysToCompleteCourse[i] = newNumDaysToComplete[i];
}

void Student::print()
{
	cout << left << setw(5) << studentId;
	cout << left << setw(10) << firstName;
	cout << left << setw(10) << lastName;
	cout << left << setw(30) << emailAddress;
	cout << left << setw(10) << age;
	cout << left << setw(10) << numberOfDaysToCompleteCourse[0];
	cout << left << setw(10) << numberOfDaysToCompleteCourse[1];
	cout << left << setw(10) << numberOfDaysToCompleteCourse[2];
}


// Destructor
Student::~Student()
{	
	if (numberOfDaysToCompleteCourse != nullptr)
	{
		delete[] numberOfDaysToCompleteCourse;
		numberOfDaysToCompleteCourse = nullptr;
	}
};




