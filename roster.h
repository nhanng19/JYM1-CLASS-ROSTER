#pragma once
#include "student.h"

class Roster
{
public:
    // Maximum number of students in the roster.
    const static int numStudents = 5;
    // Array to store pointers to Student.
    Student *classRosterArray[numStudents];
    // Keep track of the last added Student.
    int LastStudentIndex = -1;

public:
    Roster();
    ~Roster();
    void parse(string row);
    void add(string StudentID, string FirstName, string LastName, string Email, int Age, int Days1, int Days2, int Days3, DegreeProgram degreeprogram);
    void printAll();
    void printAverageDaysInCourse(string StudentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeprogram);
    void remove(string StudentID);
};
