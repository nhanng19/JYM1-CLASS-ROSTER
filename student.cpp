#pragma once
#include "student.h"

// Default constructor to initializes variables with default values.

Student::Student() {
    this->StudentID = "";
    this->FirstName = "";
    this->LastName = "";
    this->EmailAddress = "";
    this->Age = 0;
    for (int i = 0; i < CourseDays; i++) {
        this->Days[i] = 0;
    }
    this->degreeProgram = DegreeProgram::SECURITY;
}

// Constructor with provided values to initialize variables.

Student::Student(string StudentId, string FirstName, string LastName, string EmailAddress, int Age, int Days[], DegreeProgram degreeProgram) {
    this->StudentID = StudentId;
    this->FirstName = FirstName;
    this->LastName = LastName;
    this->EmailAddress = EmailAddress;
    this->Age = Age;
    for (int i = 0; i < CourseDays; i++) {
        this->Days[i] = Days[i];
    }
    this->degreeProgram = degreeProgram;
}

// Destructor 

Student::~Student() {}

// Accessor / getter methods for retrieving variable values.

string Student::getStudentID() { 
    return this->StudentID; 
}

string Student::getFirstName() { 
    return this->FirstName; 
}

string Student::getLastName() { 
    return this->LastName; 
}

string Student::getEmailAddress() { 
    return this->EmailAddress; 
}

int Student::getAge() { 
    return this->Age; 
};

int *Student::getDays() { 
    return this->Days; 
}

DegreeProgram Student::getDegreeProgram() { 
    return this->degreeProgram; 
}

// Mutator / setter methods for updating variable values.

void Student::setStudentID(string StudentID) { 
    this->StudentID = StudentID; 
}

void Student::setFirstName(string FirstName) { 
    this->FirstName = FirstName; 
}

void Student::setLastName(string LastName) { 
    this->LastName = LastName; 
}

void Student::setEmailAddress(string EmailAddress) { 
    this->EmailAddress = EmailAddress; 
}

void Student::setAge(int Age) { 
    this->Age = Age; 
}

void Student::setDays(int Days[]) {
    for (int i = 0; i < CourseDays; i++) {
        this->Days[i] = Days[i];
    }
}

void Student::setDegreeProgram(DegreeProgram degreeprogram) {
     this->degreeProgram = degreeprogram; 
}

// Print method outputs student information.

void Student::print() {
    cout << getStudentID() << '\t'
         << getFirstName() << '\t'
         << getLastName() << '\t'
         << getEmailAddress() << '\t'
         << getAge() << '\t'
         << getDays()[0] << ',' << getDays()[1] << ',' << getDays()[2] << '\t'
         << degreeProgramStrings[getDegreeProgram()] << '\n';
}
