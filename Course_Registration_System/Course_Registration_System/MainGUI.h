#ifndef MAINGUI_H_INCLUDED
#define MAINGUI_H_INCLUDED

#include <typeinfo>
#include "Initialize.h"
#include "studentProfile.h"
#include "staffProfile.h"
#include "openCourseRegistration.h"
#include "closeCourseRegistration.h"
#include "studentScoreboard.h"
#include"createNewYear.h"
#include "Student.h"
#include "Staff.h"
#include"createNewCourse.h"
#include"updateStudentResults.h"
#include"viewScoreBoard.h"
#include"publishCourse.h"
void drawMainGUI(Student& st, bool isStudent) {
    int baseX = 30, id;
    while (1) {
        drawText(posCenter("COURSE REGISTRATION SYSTEM"), 1, "COURSE REGISTRATION SYSTEM");
        drawText(baseX, 3, "1. Profile"); //done
        drawText(baseX, 4, "2. Course Registration"); 
        drawText(baseX, 5, "3. Exit");
        drawText(posCenter("Press a number: : "), 6, "Press a number: : ");

        cin >> id;
        system("cls");

        if (id == 1) {
            drawStudentProfile(st);
        }
        else if (id == 2) { drawOpenCourse(st); }
        else {
            return;
        }
    }
}

void drawMainGUI(Staff& st, bool isStudent) {
    int baseX = 30, id;
    while (1) {
        drawText(posCenter("COURSE REGISTRATION SYSTEM"), 1, "COURSE REGISTRATION SYSTEM");
        drawText(baseX, 3, "1. Profile");
        drawText(baseX, 4, "2. Open Course Registration");
        drawText(baseX, 5, "3. Close Course Registration");
        drawText(baseX, 6, "4. Create New School Year");
        drawText(baseX, 7, "5. Create New Course");
        drawText(baseX, 8, "6. Update Student Results");
        drawText(baseX, 9, "7. View Scoreboard of A Class");
        drawText(baseX, 10, "8. Publish Course");
        drawText(baseX, 11, "9. Exit");

        drawText(posCenter("Press a number: : "), 12, "Press a number: : ");

        cin >> id;
        system("cls");

        if (id == 1) {
            drawStaffProfile(st); //done
        }
        else if (id == 2) drawOpenCourse(st); //done
        else if (id == 3) drawCloseCourse(st); //done
        else if (id == 4) createNewYear(st); //done
        else if (id == 5) createNewCourse(st); //done
        else if (id == 6) updateStudentResults(st); //done
        else if (id == 7) viewScoreBoard(st);
        else if (id == 8) publishCourse(st);
        else {
            return;
        }
    }
}

#endif // MAINGUI_H_INCLUDED
