#pragma once
#include"Staff.h"
#include"Initialize.h"
#include"other.h"
struct Link {
    string year = "";
    int semester = 0;
    string courseID = "";
    string link = "";
};

void changeYear(Link& link) {
    string new_link;
    drawText(baseX, 3, "1. School Year: " + blank);
    drawText(baseX, 3, "1. School Year: ");
    cin.ignore();
    getline(cin, new_link);
    link.year = new_link;
}

void changeSemester(Link& link) {
    int new_link;
    drawText(baseX, 4, "2. Semester: " + blank);
    drawText(baseX, 4, "2. Semester: ");
    cin.ignore();
    cin >> new_link;
    link.semester = new_link;
}

void changeCourseID(Link& link) {
    string new_link;
    drawText(baseX, 5, "3. Course ID: " + blank);
    drawText(baseX, 5, "3. Course ID: ");
    cin.ignore();
    getline(cin, new_link);
    link.courseID = new_link;
}

void changeLinkCSV(Link& link) {
    string new_link;
    drawText(baseX, 6, "4. Link CSV: " + blank);
    drawText(baseX, 6, "4. Link CSV: ");
    cin.ignore();
    getline(cin, new_link);
    link.link = new_link;
}

void updateStudentResults(const Staff& st) {
    system("cls");
    int id;
    Link link;
    do {
        drawText(posCenter("Update Results: "), 1, "Update Results: ");
        drawText(baseX, 3, "1. School Year: ");  cout << link.year;
        drawText(baseX, 4, "2. Semester: "); cout << link.semester;
        drawText(baseX, 5, "3. Course ID: "); cout << link.courseID;
        drawText(baseX, 6, "4. Link CSV: "); cout << link.link;
        drawText(baseX, 7, "5. Continue");
        drawText(baseX, 8, "6. Exit");
        drawText(posCenter("Press a number to change/view information: "), 9, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) changeYear(link);
        else if (id == 2) { changeSemester(link); }
        else if (id == 3) { changeCourseID(link); }
        else if (id == 4) { changeLinkCSV(link); }
        else if (id == 5) { 
            //do something here
        }
        system("cls");
    } while (id != 6);
    system("cls");
}