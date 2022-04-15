#pragma once
#include"Initialize.h"
#include"SchoolYear.h"
#include"Staff.h"
#include"other.h"

void changeYearName(SchoolYear& ny) {
    string new_name;
    drawText(baseX, baseY + 0, "1. Name: " + blank);
    drawText(baseX, baseY + 0, "1. Name: ");
    cin.ignore();
    getline(cin, new_name);
    ny.name = new_name;
}

void changeOrder(Semester& new_c) {
    drawText(baseX, baseY + 0, "1. Order: " + blank);
    drawText(baseX, baseY + 0, "1. Order: ");
    cin >> new_c.order;
}

void changeStartDate(Semester& new_c) {
    string new_date;
    drawText(baseX, baseY + 1, "2. Start Date: " + blank);
    drawText(baseX, baseY + 1, "2. Start Date: ");
    cin.ignore();
    getline(cin, new_date);
    validDate(new_date, new_c.start_date);
}

void changeEndDate(Semester& new_c) {
    string new_date;
    drawText(baseX, baseY + 2, "3. End Date: " + blank);
    drawText(baseX, baseY + 2, "3. End Date: ");
    cin.ignore();
    getline(cin, new_date);
    validDate(new_date, new_c.end_date);
}

void createSemester(SchoolYear& ny) {
    system("cls");
    int id;
    Semester new_sem;
    do {
        drawText(posCenter("ADDING SEMESTER"), 1, "ADDING SEMESTER");
        drawText(baseX, baseY + 0, "1. Order: "); cout << new_sem.order;
        drawText(baseX, baseY + 1, "2. Start Date: "); cout << new_sem.start_date.day << "/" << new_sem.start_date.month << "/" << new_sem.start_date.year;
        drawText(baseX, baseY + 2, "3. End Date: "); cout << new_sem.end_date.day << "/" << new_sem.end_date.month << "/" << new_sem.end_date.year;
        drawText(baseX, baseY + 3, "4. Create and Continue:");
        drawText(baseX, baseY + 4, "5. Create and Exit:");
        drawText(posCenter("Press a number to change/view information: "), baseY + 5, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeOrder(new_sem); }
        else if (id == 2) { changeStartDate(new_sem); }
        else if (id == 3) { changeEndDate(new_sem); }
        else {
            //do something here
        }
        system("cls");
    } while (id != 5);
    system("cls");
}


void createNewYear(const Staff& st) {
    system("cls");
    int id;
    SchoolYear new_year;
    do {
        drawText(posCenter("NEW SCHOOL YEAR"), 1, "NEW SCHOOL YEAR");
        drawText(baseX, baseY + 0, "1. Name: "); cout << new_year.name;
        drawText(baseX, baseY + 1, "2. Continue to create semester: ");
        drawText(baseX, baseY + 2, "3. Create this school year: ");
        drawText(baseX, baseY + 3, "4. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 4, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeYearName(new_year); }
        else if (id == 2) { createSemester(new_year); }
        else if (id == 3) {
            //do something here
        }
        system("cls");
    } while (id != 4);
    system("cls");
}