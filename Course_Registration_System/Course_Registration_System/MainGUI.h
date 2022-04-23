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
#include"viewClass.h"
#include"viewCourse.h"

void drawMainGUI(Class& HCMUS, Student& st, bool isStudent) {
    int baseX = 30, id, baseY=3;
    while (1) {
        drawText(baseX * 2 + 10, baseY - 2, "Welcome back, " + st.user_info.firstname + " " + st.user_info.lastname + "!");
        drawText(baseX * 2 + 10, baseY + 22, "University of Natural Science");
        drawText(posCenter("COURSE REGISTRATION SYSTEM"), baseY , "------------------------------");
        drawText(posCenter("COURSE REGISTRATION SYSTEM"), baseY + 1, "| COURSE REGISTRATION SYSTEM |");
        drawText(posCenter("COURSE REGISTRATION SYSTEM"), baseY + 2, "------------------------------");
        drawText(baseX, baseY + 3, "1. Your Profile"); //done
        drawText(baseX, baseY + 5, "2. Your Class");
        drawText(baseX, baseY + 7, "3. Your Courses");
        drawText(baseX, baseY + 9, "4. View Course Registration");
        drawText(baseX, baseY + 11, "5. Exit");
        drawText(posCenter("Your Choice: "), baseY + 13, "Your Choice: ");

        cin >> id;
        system("cls");

        if (id == 1) {
            drawStudentProfile(HCMUS, st);
        }
        else if (id == 2) { viewClass(st); }
        else if (id == 3) { viewCourse(st); }
        else if (id == 4) { drawOpenCourse(st);}
        else {
            return;
        }
    }
}

void drawMainGUI(Class& HCMUS, Staff& st, bool isStudent) {
    int baseX = 30, id, baseY=3;
    while (1) {
        drawText(baseX * 2 + 8, baseY - 2, "Welcome back, " + st.user_info.firstname + " " + st.user_info.lastname + "!");
        drawText(baseX * 2 + 10, baseY + 22, "University of Natural Science");
        drawText(posCenter("COURSE REGISTRATION SYSTEM"), baseY - 1, "------------------------------");
        drawText(posCenter("COURSE REGISTRATION SYSTEM"), baseY ,    "| COURSE REGISTRATION SYSTEM |");
        drawText(posCenter("COURSE REGISTRATION SYSTEM"), baseY + 1, "------------------------------");
        drawText(baseX, baseY + 3, "1. Your Profile");
        drawText(baseX, baseY + 5, "2. Open Course Registration");
        drawText(baseX, baseY + 7, "3. Close Course Registration");
        drawText(baseX, baseY + 9, "4. Update School Year");
        drawText(baseX, baseY + 11, "5. Update Student Results");
        drawText(baseX, baseY + 13, "6. View Score Board");
        drawText(baseX, baseY + 15, "7. Publish Course");
        drawText(baseX, baseY + 17, "8. Exit");
        drawText(posCenter("Your Choice: "), baseY+21, "Your Choice: ");

        cin >> id;
        system("cls");

        if (id == 1) {
            drawStaffProfile(HCMUS, st); //done
        }
        else if (id == 2) drawOpenCourse(st); //done
        else if (id == 3) drawCloseCourse(st); //done
        else if (id == 4) createNewYear(HCMUS, st); //done
        else if (id == 5) updateStudentResults(st); //done
        else if (id == 6) viewScoreBoard(st);
        else if (id == 7) publishCourse(HCMUS, st);
        else {
            return;
        }
    }
}

#endif // MAINGUI_H_INCLUDED
