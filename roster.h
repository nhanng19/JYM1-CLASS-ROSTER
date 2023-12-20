#pragma once
#include "student.h"
#include <iomanip>

class Roster
{
private:
    const static int numberofStudents = 5;

public:
    ~Roster();
    int lastIndex = -1;
    Student *classRosterArray[numberofStudents];
    void parse(string row);
    void add(string sID,
             string sFirstName,
             string sLastName,
             string sEmail,
             int sAge,
             int sCompDays1,
             int sCompDays2,
             int sCompDays3,
             DegreeProgram dp);

    void removeID(string sID);
    void printAll();
    void printAverageDaysInCourse(string sID);
    void printInvalidEmail();
    void printByDegreeProgram(DegreeProgram dp);
};
