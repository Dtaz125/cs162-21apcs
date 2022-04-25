#pragma once
#include <iostream>
#include"Student.h"
#include"Staff.h"
#include"CourseRegistration.h"
#include"Initialize.h"
#include"other.h"
using namespace std;

void drawCloseCourse(const Student& st) {

}

void drawCloseCourse(Class& HCMUS, const Staff& st) {
    int id, baseY=3;
    CourseRegistration new_c;
    do {
        drawText(posCenter("CLOSING COURSE REGISTRATION"), baseY, "-------------------------------");
        drawText(posCenter("CLOSING COURSE REGISTRATION"), baseY + 1, "| CLOSING COURSE REGISTRATION |");
        drawText(posCenter("CLOSING COURSE REGISTRATION"), baseY + 2, "-------------------------------");
        drawText(baseX, baseY + 4, "1. School year: "); cout << new_c.syear;
        drawText(baseX, baseY + 6, "2. Semester: "); cout << new_c.semester;
        drawText(baseX, baseY + 8, "   Start Date: "); cout << new_c.start_date.day << "/" << new_c.start_date.month << "/" << new_c.start_date.year;
        drawText(baseX, baseY + 10, "   End Date: "); cout << new_c.end_date.day << "/" << new_c.end_date.month << "/" << new_c.end_date.year;
        drawText(baseX, baseY + 12, "3. View all courses: "); //cout << new_c.active;
        drawText(baseX, baseY + 14, "4. Active: "); cout << new_c.active;
        drawText(baseX, baseY + 16, "5. Exit: ");
        drawText(posCenter("Press a number to change/view information: "), baseY + 18, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeSchoolyear(new_c, baseX, baseY+4, "1. School year: "); }
        else if (id == 2) { changeSemester(new_c, baseX, baseY+6, "2. Semester: "); }
        else if (id == 3) {
            viewRegisCourse(new_c);
        }
        else if (id == 4) {
            new_c.active ^= 1;
            outputRegisData(new_c);
            for (int i = 0; i < new_c.numcourse; i++){
                travelCourse(it){
                    if (HCMUS.course_list[it].id == new_c.courseID[i]){
                        for (int j = 0; j < new_c.curstudent[i]; j++){
                            Score sc;
                            sc.id = new_c.students[i][j].first;
                            sc.fullname = new_c.students[i][j].second;
                            HCMUS.course_list[it].student_score.add(sc);
                        }
                        break;
                    }
                }
            }
            outputCourseData(HCMUS);
        }
        inputRegisData(new_c, new_c.syear, new_c.semester);
        system("cls");
    } while (id != 5);
}
