#pragma once
#include"Staff.h"
#include"Initialize.h"
#include"other.h"
#include"Link.h"

void findCourse(Link& link) {

}

void findClass(Link& link) {

}
void viewScoreBoard(const Staff& st) {
    system("cls");
    int id;
    Link link;
    do {
        drawText(posCenter("View Score Board: "), 1, "View Score Board: ");
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