#pragma once
#include "roster.h"

// Default constructor.

Roster::Roster(){}

void Roster::parse(string studentData) {
    // Default to SECURITY degree program, updates based on last character of argument.
    DegreeProgram degreeProgram = SECURITY; 
    if (studentData.back() == 'K') {
        degreeProgram = NETWORK;
    }
    else if (studentData.back() == 'E') {
        degreeProgram = SOFTWARE;
    }

    // Split the input string into separte fields
    int start = 0;
    int end = studentData.find(',');

    string fields[8];

    for (int i = 0; i < 8; i++) {
        fields[i] = studentData.substr(start, end - start);
        start = end + 1;
        end = studentData.find(',', start);
    }

    add(fields[0], fields[1], fields[2], fields[3],
        stoi(fields[4]), stoi(fields[5]), stoi(fields[6]), stoi(fields[7]), degreeProgram);
}

// Create and add a new Student to the roster.

void Roster::add(string StudentID, string FirstName, string LastName, string Email, int Age, int Days1, int Days2, int Days3, DegreeProgram degreeProgram) {
    int DaysInCourse[3] = {
        Days1, 
        Days2,
        Days3
    };

    classRosterArray[++LastStudentIndex] = new Student(StudentID, FirstName, LastName, Email, Age, DaysInCourse, degreeProgram);
}

// Remove a student from the roster based on their StudentID.

void Roster::remove(string StudentID) {
    bool success = false;
    for (int i = 0; i <= Roster::LastStudentIndex; i++) {
        if (classRosterArray[i]->getStudentID() == StudentID)
        {
            success = true;
            if (i < numStudents - 1)
            {
                Student *temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::LastStudentIndex--;
        }
    }
    if (success) {
        cout << StudentID << " succesfully removed from roster." << endl
             << std::endl;
        this->printAll();
    } else {
        cout << "No students found with that ID." << std::endl
             << std::endl;
    }
}

// Print each student's information.

void Roster::printAll() {
    for (int i = 0; i <= LastStudentIndex; i++) {
        Student *currentStudent = classRosterArray[i];
        currentStudent->print();
    }
}

// Print a student average days in a course.

void Roster::printAverageDaysInCourse(string StudentID) {
    for (int i = 0; i <= Roster::LastStudentIndex; i++) {
        if (classRosterArray[i]->getStudentID() == StudentID) {
            int daySums = classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2];
            cout << " Student with ID ";
            cout << StudentID;
            cout << " averages ";
            cout << daySums / 3;
            cout << " days in a course.";
        }
    }
    cout << endl;
}

// Check and print any invalid emails.

void Roster::printInvalidEmails() {
    bool invalidEmails = false;
    for (int i = 0; i <= Roster::LastStudentIndex; i++) {
        string emailAddress = classRosterArray[i]->getEmailAddress();
        if (emailAddress.find('@') == string::npos ||
            emailAddress.find('.') == string::npos ||
            emailAddress.find(' ') != string::npos)
        {
            invalidEmails = true;
            cout << emailAddress << ": " << emailAddress << endl;
        }
    }
    if (!invalidEmails) {
        cout << "All emails are valid." << endl;
    }
}

// Print Students in the provided degreeProgram.

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= Roster::LastStudentIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram)
            classRosterArray[i]->print();
    }
    cout << std::endl;
}

// Destructor to release memory allocated for each student in the roster.

Roster::~Roster() {
    cout << "Roster destructor called." << std::endl
         << std::endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Releasing memory for Student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
};
