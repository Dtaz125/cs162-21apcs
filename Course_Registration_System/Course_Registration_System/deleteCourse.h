#pragma once
#include"Initialize.h"
#include"other.h"
#include"Staff.h"
#include"Link.h"
void deleteCourse(SchoolYear& st) {
    int id, baseY = 3;
    Link link;
    do {
        system("cls");
        drawText(posCenter("DELETE COURSE"), baseY, "--------------");
        drawText(posCenter("DELETE COURSE"), baseY + 1, "| DELETE COURSE |");
        drawText(posCenter("DELETE COURSE"), baseY + 2, "--------------");
        drawText(baseX, baseY + 3, "1. Course ID: "); cout << link.courseID;
        drawText(baseX, baseY + 5, "2. School year: "); cout << link.year;
        drawText(baseX, baseY + 7, "3. Delete");
        drawText(baseX, baseY + 9, "4. Exit");
        //display course have created here
        drawText(posCenter("Press a number to change/view information: "), baseY + 11, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeCourseID(link, baseX, baseY + 3, "1. Course ID: "); }
        else if (id == 2) { changeYear(link, baseX, baseY + 5, "2. School year: "); }
        else {
            //do something here
        }
        system("cls");
    } while (id != 4);
}