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
        drawText(baseX, baseY + 3, "1. Course ID: "); cout << link.courseID;
        drawText(baseX, baseY + 5, "2. Link CSV: "); cout << link.link;
        drawText(baseX, baseY + 7, "3. Update");
        drawText(baseX, baseY + 9, "4. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 11, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeCourseID(link, baseX, baseY + 3, "1. Course ID: "); }
        else if (id == 2) { changeLinkCSV(link, baseX, baseY + 5, "2. Link CSV: "); }
        else if (id == 3) { 
            Class tmp;
            inputCourseData(tmp);
            int index = tmp.getCourse(link.courseID);
            if (index != -1) {
                readCSV_Scoreboard(tmp.course_list[index], link.link);
            }
            outputCourseData(tmp);
            drawText(baseX, baseY + 7, "Update Completed!");
        }
        system("cls");
    } while (id != 4);
    system("cls");
}
