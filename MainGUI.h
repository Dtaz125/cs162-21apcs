#ifndef MAINGUI_H_INCLUDED
#define MAINGUI_H_INCLUDED

#include "Initialize.h"
#include "studentProfile.h"
#include "openCourseRegistration.h"
#include "closeCourseRegistration.h"
#include "studentScoreboard.h"

///#include "Student.h"

void drawMainGUI(Student &st){
    int baseX = 30, id;
    while (1){
        drawText(posCenter("Course Registration System"), 1, "Course Registration System");
        drawText(baseX, 3, "1. Profile");
        drawText(baseX, 4, "2. Open course registration");
        drawText(baseX, 5, "3. Close course registration");
        drawText(baseX, 6, "4. View scoreboard");
        drawText(baseX, 7, "5. Update a course (staff only)");
        drawText(baseX, 8, "6. Update a student result(staff only)");
        drawText(baseX, 9, "7. View the scoreboard of a class(staff only)");
        drawText(baseX, 10, "8. Exit");

        drawText(posCenter("Press a number: : "), 12, "Press a number: : ");

        cin >> id;
        system("cls");

        if (id == 1){
            drawStudentProflie(st);
        }
        else if (id == 2){drawOpenCourse(st);}
        else if (id == 3){drawCloseCourse(st);}
        else if (id == 4){drawScoreboard(st);}
        else if (id == 5){}
        else if (id == 6){}
        else if (id == 7){}
        else {
            return ;
        }
    }
}

#endif // MAINGUI_H_INCLUDED
