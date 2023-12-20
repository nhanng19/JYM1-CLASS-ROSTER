#pragma once
#include "student.h"
#include "degree.h"

Student::Student() // empty Constructor

{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->ageofStudent = 0;
    for (int i = 0; i < daystoComplete; i++)
        this->daystoComp[i] = 0;
    this->degreeProgram = DegreeProgram::UNKNOWN;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int ageofStudent, int daystoComp[], DegreeProgram degreeProgram)

{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->ageofStudent = ageofStudent;
    for (int i = 0; i < daystoComplete; i++)
        this->daystoComp[i] = daystoComp[i];
    this->degreeProgram = degreeProgram;
}

Student::~Student() {} // Deconstructor

// getters
string Student::getID()
{
    return this->studentID;
}

string Student::getFirstName()
{
    return this->firstName;
}

string Student::getLastName()
{
    return this->lastName;
}

string Student::getEmailAddress()
{

    return this->emailAddress;
}

int Student::getAgeofStudent()
{

    return this->ageofStudent;
}

int *Student::getDaystoComp()
{

    return this->daystoComp;
}

DegreeProgram Student::getDegreeProgram()
{

    return this->degreeProgram;
}

// setters

void Student::setID(string studentID)
{
    this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{

    this->emailAddress = emailAddress;
}

void Student::setAgeofStudent(int ageofStudent)
{
    this->ageofStudent = ageofStudent;
}

void Student::setDaystoComp(int daystoComp[])
{
    this->daystoComp[0] = daystoComp[0];
    this->daystoComp[1] = daystoComp[1];
    this->daystoComp[2] = daystoComp[2];
}

void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }

void Student::printHeader()

{
    cout << "Student ID|First Name|Last Name||Email Address|Age|Days to Complete Course|Degree Program\n";
}

void Student::print()

{
    cout << this->getID() << '\t';
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmailAddress() << '\t';
    cout << this->getAgeofStudent() << '\t';
    cout << this->getDaystoComp()[0] << ',';
    cout << this->getDaystoComp()[1] << ',';
    cout << this->getDaystoComp()[2] << '\t';
    cout << degreeProgramStrings[this->getDegreeProgram()] << '\n'; // degreeprogram to string
}
