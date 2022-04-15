#pragma once
#include <iostream>
#include"Student.h"
#include"Staff.h"
#include"Initialize.h"
#include"other.h"
#include"CourseRegistration.h"
using namespace std;

void changeName(CourseRegistration& new_c) {
    string new_name;
    drawText(baseX, baseY + 0, "1. Name: " + blank);
    drawText(baseX, baseY + 0, "1. Name: ");
    cin.ignore();
    getline(cin, new_name);
    new_c.name = new_name;
}

void changeStartDate(CourseRegistration& new_c) {
    string new_date;
    drawText(baseX, baseY + 1, "2. Start Date: " + blank);
    drawText(baseX, baseY + 1, "2. Start Date: ");
    cin.ignore();
    getline(cin, new_date);
    validDate(new_date, new_c.start_date);
}

void changeEndDate(CourseRegistration& new_c) {
    string new_date;
    drawText(baseX, baseY + 2, "3. End Date: " + blank);
    drawText(baseX, baseY + 2, "3. End Date: ");
    cin.ignore();
    getline(cin, new_date);
    validDate(new_date, new_c.end_date);
}

void drawOpenCourse(const Student& st) {

}

void drawOpenCourse(const Staff& st) {
    int id;
    CourseRegistration new_c;
    do {
        drawText(posCenter("CREATE COURSE REGISTRATION"), 1, "CREATE COURSE REGISTRATION");
        drawText(baseX, baseY + 0, "1. Name: "); cout << new_c.name;
        drawText(baseX, baseY + 1, "2. Start Date: "); cout << new_c.start_date.day << "/" << new_c.start_date.month << "/" << new_c.start_date.year;
        drawText(baseX, baseY + 2, "3. End Date: "); cout << new_c.end_date.day << "/" << new_c.end_date.month << "/" << new_c.end_date.year;
        drawText(baseX, baseY + 3, "4. Continue to create: ");
        drawText(baseX, baseY + 4, "5. Exit: ");
        drawText(posCenter("Press a number to change/view information: "), baseY + 5, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeName(new_c); }
        else if (id == 2) { changeStartDate(new_c); }
        else if (id == 3) { changeEndDate(new_c); }
        else {
            //do something here
        }
        system("cls");
    } while (id != 5);
}
