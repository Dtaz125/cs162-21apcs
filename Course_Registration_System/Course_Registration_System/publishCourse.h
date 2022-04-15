#pragma once
#include"Staff.h"
#include"other.h"
#include"Initialize.h"
void publishCourse(Staff& st) {
    int baseX = 30, id;
    Link link;
    while (1) {
        drawText(posCenter("PUBLISHING COURSE"), 1, "PUBLISHING COURSE");
        drawText(baseX, 3, "1. School Year: ");
        drawText(baseX, 4, "2. Semester: ");
        drawText(baseX, 5, "3. Course ID: ");
        drawText(baseX, 6, "4. Publish: ");
        drawText(baseX, 7, "5. Exit: ");
        drawText(posCenter("Press a number: : "), 8, "Press a number: : ");

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