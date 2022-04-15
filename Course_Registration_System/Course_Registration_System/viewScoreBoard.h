#pragma once
#include"Staff.h"
#include"Initialize.h"
#include"other.h"
#include"Link.h"


void changeClass(Link& link) {
    string new_link;
    drawText(baseX, 4, "2. Class: " + blank);
    drawText(baseX, 4, "2. Class: ");
    cin.ignore();
    getline(cin, new_link);
    link.classname = new_link;
}

void findCourse(Link& link) {
    system("cls");
    int id;
    do {
        drawText(posCenter("VIEW COURSE SCOREBOARD"), 1, "VIEW COURSE SCOREBOARD");
        drawText(baseX, 3, "1. School Year: "); cout << link.year;
        drawText(baseX, 4, "2. Semester: "); cout << link.semester;
        drawText(baseX, 5, "3. Course ID: "); cout << link.courseID;
        drawText(baseX, 6, "4. Continue: ");
        drawText(baseX, 7, "5. Exit: ");
        drawText(posCenter("Press a number to change/view information: "), 8, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) changeYear(link);
        else if (id == 2) { changeSemester(link); }
        else if (id == 3) { changeCourseID(link); }
        else if (id == 4){

        }
        system("cls");
    } while (id != 5);
    system("cls");
}

void findClass(Link& link) {
    system("cls");
    int id;
    do {
        drawText(posCenter("VIEW CLASS SCOREBOARD"), 1, "VIEW CLASS SCOREBOARD");
        drawText(baseX, 3, "1. School Year: "); cout << link.year;
        drawText(baseX, 4, "2. Class: "); cout << link.classname;
        drawText(baseX, 5, "3. Continue: ");
        drawText(baseX, 6, "4. Exit: ");
        drawText(posCenter("Press a number to change/view information: "), 7, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) changeYear(link);
        else if (id == 2) { changeClass(link); }
        else if (id == 3) {

        }
        system("cls");
    } while (id != 4);
    system("cls");
}
void viewScoreBoard(const Staff& st) {
    system("cls");
    int id;
    Link link;
    do {
        drawText(posCenter("VIEW SCOREBOARD"), 1, "VIEW SCOREBOARD");
        drawText(baseX, 3, "1. Course: ");  
        drawText(baseX, 4, "2. Class: "); 
        drawText(baseX, 5, "3. Exit");
        drawText(posCenter("Press a number to change/view information: "), 6, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) findCourse(link);
        else if (id == 2) { findClass(link); }
        system("cls");
    } while (id != 3);
    system("cls");
}