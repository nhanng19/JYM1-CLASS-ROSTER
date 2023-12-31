#pragma once
#include <string>
#include <iostream>
#include "degree.h"

using namespace std;

class Student {
public:
    // Maximum number of days for courses.
    const static int CourseDays = 3;

private:
    string StudentID;
    string FirstName;
    string LastName;
    string EmailAddress;
    int Age;
    int Days[CourseDays];
    DegreeProgram degreeProgram;

public:
    Student();
    Student(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int Days[], DegreeProgram degreeProgram);
    ~Student();

    // Accessor / getter methods for retrieving variable values.

    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int *getDays();
    DegreeProgram getDegreeProgram();

    // Mutator / setter methods for updating variable values.

    void setStudentID(string StudentID);
    void setFirstName(string FirstName);
    void setLastName(string LastName);
    void setEmailAddress(string EmailAddress);
    void setAge(int Age);
    void setDays(int Days[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // Print method outputs student information.

    void print();
};
