#pragma once
#include"SchoolYear.h"
#include"Course.h"
#include"other.h"
#include"Initialize.h"
#include"semesterData.h"
void changeOrder(Semester& new_c) {
    drawText(baseX, baseY + 0, "1. Order: " + blank);
    drawText(baseX, baseY + 0, "1. Order: ");
    cin >> new_c.order;
}

void changeStartDate(Semester& new_c) {
    string new_date;
    drawText(baseX, baseY + 2, "2. Start Date: " + blank);
    drawText(baseX, baseY + 2, "2. Start Date: ");
    cin.ignore();
    getline(cin, new_date);
    validDate(new_date, new_c.start_date);
}

void changeEndDate(Semester& new_c) {
    string new_date;
    drawText(baseX, baseY + 4, "3. End Date: " + blank);
    drawText(baseX, baseY + 4, "3. End Date: ");
    cin.ignore();
    getline(cin, new_date);
    validDate(new_date, new_c.end_date);
}

void createSemester(SchoolYear& ny) {
    string Folder = "system/schoolyears/" + ny.name;
    system("cls");
    int id, baseY = 3;
    Semester new_sem;
    do {
        system("cls");
        drawText(posCenter("ADDING SEMESTER"), baseY , "-------------------");
        drawText(posCenter("ADDING SEMESTER"), baseY + 1, "| ADDING SEMESTER |");
        drawText(posCenter("ADDING SEMESTER"), baseY + 2, "-------------------");
        drawText(baseX, baseY + 4, "1. Order : "); cout << new_sem.order;
        drawText(baseX, baseY + 6, "2. Start Date: "); cout << new_sem.start_date.day << "/" << new_sem.start_date.month << "/" << new_sem.start_date.year;
        drawText(baseX, baseY + 8, "3. End Date: "); cout << new_sem.end_date.day << "/" << new_sem.end_date.month << "/" << new_sem.end_date.year;
        drawText(baseX, baseY + 10, "4. Create and next");
        drawText(baseX, baseY + 12, "5. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 14, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeOrder(new_sem); }
        else if (id == 2) { changeStartDate(new_sem); }
        else if (id == 3) { changeEndDate(new_sem); }
        else if (id == 4) {
            createSemesterFolder(Folder, new_sem);
            createNewCourse(ny);
        }
        system("cls");
    } while (id != 5);
    system("cls");
}
