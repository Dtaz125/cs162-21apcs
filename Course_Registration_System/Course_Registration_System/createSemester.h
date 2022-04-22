#pragma once
#include"SchoolYear.h"
#include"Course.h"
#include"other.h"
#include"Initialize.h"
#include"semesterData.h"
#include"Initialize.h"
#include"deleteCourse.h"
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

void createSemester(Class& HCMUS, SchoolYear& ny) {
    string Folder = "system/schoolyears/" + ny.name;
    system("cls");
    int id, baseY = 3;
    Semester new_sem;
    string semesterFolder = Folder + "/semester0";
    do {

        system("cls");
        drawText(posCenter("SEMESTER"), baseY , "-------------------");
        drawText(posCenter("SEMESTER"), baseY + 1, "| SEMESTER |");
        drawText(posCenter("SEMESTER"), baseY + 2, "-------------------");
        drawText(baseX, baseY + 4, "1. Order : "); cout << new_sem.order;
        drawText(baseX, baseY + 6, "2. Start Date: "); cout << new_sem.start_date.day << "/" << new_sem.start_date.month << "/" << new_sem.start_date.year;
        drawText(baseX, baseY + 8, "3. End Date: "); cout << new_sem.end_date.day << "/" << new_sem.end_date.month << "/" << new_sem.end_date.year;
        drawText(baseX, baseY + 10, "4. Add Course");
        drawText(baseX, baseY + 12, "5. Remove Course");
        drawText(baseX, baseY + 14, "6. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 16, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeOrder(new_sem);
            semesterFolder = Folder + "/semester" + to_string(new_sem.order);
            createSemesterFolder(Folder, new_sem);
            inputSemesterData(semesterFolder, new_sem);
        }
        else if (id == 2) { changeStartDate(new_sem); }
        else if (id == 3) { changeEndDate(new_sem); }
        else if (id == 4) {
            createSemesterFolder(Folder, new_sem);
            createNewCourse(HCMUS, new_sem);
            outputSemesterData(semesterFolder, new_sem);
        }
        else if (id == 5) {
            deleteCourse(new_sem);
            outputSemesterData(semesterFolder, new_sem);
        }
        else{
            outputSemesterData(semesterFolder, new_sem);
        }
        system("cls");
    } while (id != 6);
    system("cls");
}
