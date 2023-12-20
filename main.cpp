#include "roster.h"
// using std::endl;

int main()

{

    const string studentData[] =
        {

            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,DeAundra,Dyson,ddyson4@wgu.edu,35,20,30,40,SOFTWARE"};

    cout << "Scripting and Programming-Applications" << std::endl;
    cout << "Program languague used is C++" << std::endl;
    cout << "Student ID: 000588248" << std::endl;
    cout << "DeAundra Dyson" << std::endl;
    cout << std::endl;

    const int numberofStudents = 5;

    Roster classRoster;
    // displays all students
    for (int i = 0; i < numberofStudents; i++)
        classRoster.parse(studentData[i]);
    cout << "Displaying all Students: " << std::endl;
    classRoster.printAll();
    cout << std::endl;

    // Displays all students by degree program
    for (int i = 0; i < 4; i++)
    {
        cout << "Displaying by degree program: " << degreeProgramStrings[i] << std::endl;
        classRoster.printByDegreeProgram((DegreeProgram)i); //*Cast to a Degree Program
    }

    // display students with invalid email
    cout << "Displaying students with invalid emails: " << std::endl;
    classRoster.printInvalidEmail();
    cout << std::endl;

    // displays average days in a course
    cout << "Displaying average days in course: " << std::endl;
    for (int i = 0; i < numberofStudents; i++)
    {

        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
    }

    // removes by ID;
    cout << "Removing student with ID A3:" << std::endl;
    classRoster.removeID("A3");
    cout << std::endl;

    classRoster.printAll(); // NEED TO PRINT IN ORDER
    cout << std::endl;

    cout << "Removing student with ID A3: " << std::endl;
    classRoster.removeID("A3 ");
    cout << std::endl;

    system("pause");
    return 0;
}