#pragma once
#include"Staff.h"
#include"other.h"
#include"Initialize.h"
void publishCourse(Staff& st) {
    int baseX = 30, id, baseY=3;
    Link link;
    while (1) {
        drawText(posCenter("PUBLISHING COURSE"), baseY+1, "PUBLISHING COURSE");
        drawText(baseX, baseY + 3, "1. School Year: ");
        drawText(baseX, baseY + 5, "2. Semester: ");
        drawText(baseX, baseY + 7, "3. Course ID: ");
        drawText(baseX, baseY + 9, "4. Publish: ");
        drawText(baseX, baseY + 11, "5. Exit: ");
        drawText(posCenter("Press a number: : "), 13, "Press a number: : ");

        cin >> id;
        system("cls");

        if (id == 1) changeYear(link); //done
        else if (id == 2) changeSemester(link); //done
        else if (id == 3) changeCourseID(link); //done
        else if (id == 4) {
            //do something here
        }
        else {
            return;
        }
    }
}
