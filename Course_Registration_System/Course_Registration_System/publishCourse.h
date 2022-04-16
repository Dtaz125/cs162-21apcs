#pragma once
#include"Staff.h"
#include"other.h"
#include"Initialize.h"
void publishCourse(Staff& st) {
    int baseY = 3, id;
    Link link;
    while (1) {
        drawText(posCenter("PUBLISHING COURSE"), baseY + 1, "PUBLISHING COURSE");
        drawText(baseX, baseY + 4, "1. School Year: ");
        drawText(baseX, baseY + 6, "2. Semester: ");
        drawText(baseX, baseY + 8, "3. Course ID: ");
        drawText(baseX, baseY + 10, "4. Publish: ");
        drawText(baseX, baseY + 12, "5. Exit: ");
        drawText(posCenter("Press a number: : "), baseY + 14, "Press a number: : ");

        cin >> id;
        system("cls");

        if (id == 1) changeYear(link, baseX, baseY + 4, "1. School Year: "); //done
        else if (id == 2) changeSemester(link, baseX, baseY + 6, "2. Semester: "); //done
        else if (id == 3) changeCourseID(link, baseX, baseY + 8, "3. Course ID: "); //done
        else if (id == 4) {
            //do something here
        }
        else {
            return;
        }
    }
}
