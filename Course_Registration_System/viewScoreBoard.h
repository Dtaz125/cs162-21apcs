#pragma once
#include"Staff.h"
#include"Initialize.h"
#include"other.h"
#include"Link.h"

void findCourse(Link& link) {
    system("cls");
    int id, baseY=3;
    do {
        drawText(posCenter("VIEW COURSE SCOREBOARD"), baseY, "--------------------------");
        drawText(posCenter("VIEW COURSE SCOREBOARD"), baseY + 1, "| VIEW COURSE SCOREBOARD |");
        drawText(posCenter("VIEW COURSE SCOREBOARD"), baseY + 2, "--------------------------");
        drawText(baseX, baseY + 3, "1. School Year: "); cout << link.year;
        drawText(baseX, baseY + 5, "2. Semester: "); cout << link.semester;
        drawText(baseX, baseY + 7, "3. Course ID: "); cout << link.courseID;
        drawText(baseX, baseY + 9, "4. Continue: ");
        drawText(baseX, baseY + 11, "5. Exit: ");
        drawText(posCenter("Press a number to change/view information: "), baseY + 13, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) changeYear(link, baseX, baseY+3, "1. School Year: ");
        else if (id == 2) { changeSemester(link, baseX, baseY + 5, "2. Semester: "); }
        else if (id == 3) { changeCourseID(link, baseX, baseY + 7, "3. Course ID: "); }
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
        drawText(posCenter("VIEW COURSE SCOREBOARD"), baseY, "-------------------------");
        drawText(posCenter("VIEW COURSE SCOREBOARD"), baseY + 1, "| VIEW CLASS SCOREBOARD |");
        drawText(posCenter("VIEW COURSE SCOREBOARD"), baseY + 2, "-------------------------");
        drawText(baseX, baseY + 3, "1. School Year: "); cout << link.year;
        drawText(baseX, baseY + 5, "2. Class: "); cout << link.classname;
        drawText(baseX, baseY + 7, "3. Continue: ");
        drawText(baseX, baseY + 9, "4. Exit: ");
        drawText(posCenter("Press a number to change/view information: "), baseY + 11, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) changeYear(link, baseX, baseY + 3, "1. School Year: ");
        else if (id == 2) { changeClass(link, baseX, baseY + 5, "2. Class: "); }
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
        drawText(posCenter("VIEW COURSE SCOREBOARD"), baseY, "-------------------");
        drawText(posCenter("VIEW COURSE SCOREBOARD"), baseY + 1, "| VIEW SCOREBOARD |");
        drawText(posCenter("VIEW COURSE SCOREBOARD"), baseY + 2, "-------------------");
        drawText(baseX, baseY + 3, "1. Course: ");
        drawText(baseX, baseY + 5, "2. Class: ");
        drawText(baseX, baseY + 7, "3. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 9, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) findCourse(link);
        else if (id == 2) { findClass(link); }
        system("cls");
    } while (id != 3);
    system("cls");
}
