#pragma once
#include <iostream>
#include"Student.h"
#include"Staff.h"
#include"Initialize.h"
#include"other.h"
#include"CourseRegistration.h"
using namespace std;

void drawOpenCourse(const Student& st) {

}

void drawOpenCourse(const Staff& st) {
    int id,baseY=3;
    CourseRegistration new_c;
    do {
        drawText(posCenter("CREATE COURSE REGISTRATION"), baseY+1, "CREATE COURSE REGISTRATION");
        drawText(baseX, baseY + 4, "1. Name: "); cout << new_c.name;
        drawText(baseX, baseY + 6, "2. Start Date: "); cout << new_c.start_date.day << "/" << new_c.start_date.month << "/" << new_c.start_date.year;
        drawText(baseX, baseY + 8, "3. End Date: "); cout << new_c.end_date.day << "/" << new_c.end_date.month << "/" << new_c.end_date.year;
        drawText(baseX, baseY + 10, "4. Continue to create: ");
        drawText(baseX, baseY + 12, "5. Exit: ");
        drawText(posCenter("Press a number to change/view information: "), baseY + 14, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeName(new_c, baseX, baseY+4, "1. Name: "); }
        else if (id == 2) { changeStartDate(new_c, baseX, baseY+6, "2. Start Date: "); }
        else if (id == 3) { changeEndDate(new_c, baseX, baseY + 8, "2. End Date: "); }
        else {
            //do something here
        }
        system("cls");
    } while (id != 5);
}
