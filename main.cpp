#include "roster.h"
#include "student.h"

int main() {
    // Print submission information.
    cout << "Course: Scripting and Programming Application C867\n"
         << "Programming Language: C++\n"
         << "WGU ID: 011180749\n"
         << "Name: Nhan Nguyen\n\n";

    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Nhan,Nguyen,nngu211@wgu.edu,23,34,25,45,SOFTWARE"};

    Roster classRoster;

    for (int i = 0; i < 5; i++) {
        classRoster.parse(studentData[i]);
    };

    cout << "------------ Displaying class roster ------------" << endl;
    cout << "\n";
    classRoster.printAll();
    cout << endl;

    cout << "------------ Displaying invalid emails ------------" << endl;
    cout << "\n";
    classRoster.printInvalidEmails();
    cout << endl;

    cout << "------------ Average days in course ------------" << endl;
    cout << "\n";
    for (int i = 0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    };

    cout << "\n";
    cout << "------------ Displaying students in software ------------" << endl;
    cout << "\n";
    classRoster.printByDegreeProgram(SOFTWARE);

    cout << endl;

    cout << "Attempting to delete student A3..." << endl;
    classRoster.remove("A3");
    cout << endl;

    cout << "Attempting to delete student A3..." << endl;
    classRoster.remove("A3");
    cout << endl;

    system("pause");

    return 0;
};