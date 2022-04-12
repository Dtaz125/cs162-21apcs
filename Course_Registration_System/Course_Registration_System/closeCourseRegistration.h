#pragma once
#include <iostream>
#include"Student.h"
#include"Staff.h"
#include"closeCourseRegistration.h"
#include"Initialize.h"
using namespace std;

void drawCloseCourse(const Student& st) {

}

void drawCloseCourse(const Staff& st) {
    int id;
    CourseRegistration new_c;
    do {
        drawText(posCenter("Close Course Registration: "), 1, "Close Course Registration: ");
        drawText(baseX, baseY + 0, "1. Name: "); cout << new_c.name;
        /*drawText(baseX, baseY + 1, "2. Start Date: "); cout << new_c.start_date.day << "/" << new_c.start_date.month << "/" << new_c.start_date.year;
        drawText(baseX, baseY + 2, "3. End Date: "); cout << new_c.end_date.day << "/" << new_c.end_date.month << "/" << new_c.end_date.year;*/
        drawText(baseX, baseY + 1, "2. Continue to close: ");
        drawText(baseX, baseY + 2, "3. Exit: ");
        drawText(posCenter("Press a number to change/view information: "), baseY + 4, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeName(new_c); }
        /*else if (id == 2) { changeStartDate(new_c); }
        else if (id == 3) { changeEndDate(new_c); }*/
        else {
            //do something here
        }
        system("cls");
    } while (id != 3);
}
