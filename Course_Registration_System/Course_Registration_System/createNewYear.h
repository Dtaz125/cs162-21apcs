#pragma once
#include"Initialize.h"
#include"SchoolYear.h"
#include"Staff.h"
#include"other.h"
#include"createNewCourse.h"
#include"createSemester.h"
#include"schoolyearData.h"
void changeYearName(SchoolYear& ny) {
    string new_name;
    drawText(baseX, baseY + 0, "1. Year: " + blank);
    drawText(baseX, baseY + 0, "1. Year: ");
    cin.ignore();
    getline(cin, new_name);
    ny.name = new_name;
}

void createNewYear(const Staff& st) {
    system("cls");
    int id, baseY=3;
    SchoolYear new_year;
    do {
        drawText(posCenter("SCHOOL YEAR"), baseY , "-------------------");
        drawText(posCenter("SCHOOL YEAR"), baseY + 1, "| SCHOOL YEAR |");
        drawText(posCenter("SCHOOL YEAR"), baseY + 2, "-------------------");
        drawText(baseX, baseY + 4, "1. Year: "); cout << new_year.name;
        drawText(baseX, baseY + 6, "2. Next ");
        //drawText(baseX, baseY + 2, "3. Create this school year: ");
        //drawText(baseX, baseY + 8, "3. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 8, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeYearName(new_year); }
        else if (id == 2){
            createSchoolYear(new_year);
            createSemester(new_year);
            break;
        }
        else if (id == 3) {
            //do something here
        }
        system("cls");
    } while (id != 2);
    system("cls");
}
