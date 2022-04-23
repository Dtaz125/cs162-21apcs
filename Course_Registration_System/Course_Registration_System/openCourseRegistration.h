#pragma once
#include <iostream>
#include"Student.h"
#include"Staff.h"
#include"Initialize.h"
#include"other.h"
#include"CourseRegistration.h"
#include"CourseRegistrationData.h"
using namespace std;

void drawOpenCourse(const Student& st){}

void drawOpenCourse(const Staff& st) {
    int id,baseY=3;
    CourseRegistration new_c;
    do {
        drawText(posCenter("CREATE COURSE REGISTRATION"), baseY , "------------------------------");
        drawText(posCenter("CREATE COURSE REGISTRATION"), baseY + 1, "| CREATE COURSE REGISTRATION |");
        drawText(posCenter("CREATE COURSE REGISTRATION"), baseY + 2, "------------------------------");
        drawText(baseX, baseY + 4, "1. School year: "); cout << new_c.syear;
        drawText(baseX, baseY + 6, "2. Semester: "); cout << new_c.semester;
        drawText(baseX, baseY + 8, "3. Start Date: "); cout << new_c.start_date.day << "/" << new_c.start_date.month << "/" << new_c.start_date.year;
        drawText(baseX, baseY + 10, "4. End Date: "); cout << new_c.end_date.day << "/" << new_c.end_date.month << "/" << new_c.end_date.year;
        drawText(baseX, baseY + 12, "5. Add courseID: ");
            for (int i = 0; i < min(3, new_c.numcourse); i++) cout << new_c.courseID[i] << ", ";
            cout << "...";
        drawText(baseX, baseY + 14, "  Max student of course: ");
        drawText(baseX, baseY + 16, "6. Cancel: ");
        drawText(posCenter("Press a number to change/view information: "), baseY + 18, "Press a number to change/view information: ");
        cin >> id;

        if (id == 1) { changeSchoolyear(new_c, baseX, baseY+4, "1. School year: "); }
        else if (id == 2) { changeSemester(new_c, baseX, baseY+6, "2. Semester: "); }
        else if (id == 3) {
            changeStartDate(new_c, baseX, baseY+8, "3. Start Date: ");
            outputRegisData(new_c);
        }
        else if (id == 4) {
            changeEndDate(new_c, baseX, baseY + 10, "4. End Date: ");
            outputRegisData(new_c);
        }
        else if (id == 5){
            addCourse(new_c, baseX, baseY + 12, "5. Add courseID: ", "  Max student of course: ");
            //do something here
            outputRegisData(new_c);
        }
        inputRegisData(new_c, new_c.syear, new_c.semester);
        system("cls");
    } while (id != 6);
}
