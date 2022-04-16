#pragma once
#include"Staff.h"
#include"Initialize.h"
#include"other.h"
#include"Link.h"


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
        drawText(posCenter("UPDATE RESULTS"), 1, "UPDATE RESULTS");
        drawText(baseX, 3, "1. Enter School Year: ");  cout << link.year;
        drawText(baseX, 4, "2. Course ID: "); cout << link.courseID;
        drawText(baseX, 5, "3. Link CSV: "); cout << link.link;
        drawText(baseX, 6, "4. Continue");
        drawText(baseX, 7, "5. Exit");
        drawText(posCenter("Press a number to change/view information: "), 8, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) changeYear(link);
        else if (id == 2) { changeCourseID(link); }
        else if (id == 3) { changeLinkCSV(link); }
        else if (id == 4) { 
            //do something here
        }
        system("cls");
    } while (id != 5);
    system("cls");
}