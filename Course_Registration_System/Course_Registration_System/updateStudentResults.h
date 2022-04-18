#pragma once
#include"Staff.h"
#include"Initialize.h"
#include"other.h"
#include"Link.h"
void updateStudentResults(const Staff& st) {
    system("cls");
    int id, baseY=3;
    Link link;
    do {
        drawText(posCenter("UPDATE RESULTS"), baseY, "------------------");
        drawText(posCenter("UPDATE RESULTS"), baseY + 1, "| UPDATE RESULTS |");
        drawText(posCenter("UPDATE RESULTS"), baseY + 2, "------------------");
        drawText(baseX, baseY + 3, "1. Enter School Year: ");  cout << link.year;
        drawText(baseX, baseY + 5, "2. Course ID: "); cout << link.courseID;
        drawText(baseX, baseY + 7, "3. Link CSV: "); cout << link.link;
        drawText(baseX, baseY + 9, "4. Continue");
        drawText(baseX, baseY + 11, "5. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 13, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) changeYear(link, baseX, baseY+3, "1. Enter School Year: ");
        else if (id == 2) { changeCourseID(link, baseX, baseY + 5, "2. Course ID: "); }
        else if (id == 3) { changeLinkCSV(link, baseX, baseY + 7, "3. Link CSV: "); }
        else if (id == 4) { 
            //do something here
        }
        system("cls");
    } while (id != 5);
    system("cls");
}
