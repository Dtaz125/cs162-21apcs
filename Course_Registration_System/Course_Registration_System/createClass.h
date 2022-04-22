#pragma once
#include"Staff.h"
#include"other.h"
#include"Initialize.h"
#include"SchoolYear.h"
#include"Class.h"
void createClass(SchoolYear& st) {
    system("cls");
    int id, baseY = 3;
    Link link;
    do {
        drawText(posCenter("CLASS"), baseY, "-------------------");
        drawText(posCenter("CLASS"), baseY + 1, "| CLASS |");
        drawText(posCenter("CLASS"), baseY + 2, "-------------------");
        drawText(baseX, baseY + 4, "1. Name: "); cout << link.classname;
        drawText(baseX, baseY + 6, "2. Link Students CSV: "); cout << link.link;
        drawText(baseX, baseY + 8, "3. Create");
        drawText(baseX, baseY + 10, "4. Exit"); 
        drawText(posCenter("Press a number to change/view information: "), baseY + 12, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeClass(link, baseX, baseY + 4, "1. Name: "); }
        else if (id == 2) { changeLinkCSV(link, baseX, baseY + 6, "2. Link Students CSV: "); }
        else if (id == 3) {

        }
        system("cls");
    } while (id != 4);
    system("cls");
}

void changeClass(SchoolYear& st) {
    /*system("cls");
    int id, baseY = 3;
    Link link;
    do {
        drawText(posCenter("CLASS"), baseY, "-------------------");
        drawText(posCenter("CLASS"), baseY + 1, "| CLASS |");
        drawText(posCenter("CLASS"), baseY + 2, "-------------------");
        drawText(baseX, baseY + 4, "1. Add Student: "); cout << link.classname;
        drawText(baseX, baseY + 6, "2. Remove Student: "); cout << link.link;
        drawText(baseX, baseY + 8, "3. Create");
        drawText(baseX, baseY + 10, "4. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 12, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeClass(link, baseX, baseY + 4, "1. Name: "); }
        else if (id == 2) { changeLinkCSV(link, baseX, baseY + 6, "2. Link Students CSV: "); }
        else if (id == 3) {

        }
        system("cls");
    } while (id != 4);*/
    system("cls");
}
void modifyClass(SchoolYear& st) {
    system("cls");
    int id, baseY = 3;
    do {
        drawText(posCenter("CLASS"), baseY, "-------------------");
        drawText(posCenter("CLASS"), baseY + 1, "| CLASS |");
        drawText(posCenter("CLASS"), baseY + 2, "-------------------");
        drawText(baseX, baseY + 4, "1. Create"); 
        drawText(baseX, baseY + 6, "2. Modify");
        drawText(posCenter("Press a number to change/view information: "), baseY + 8, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { createClass(st); }
        else if (id == 2) { changeClass(st); }
        system("cls");
    } while (id != 3);
    system("cls");
}