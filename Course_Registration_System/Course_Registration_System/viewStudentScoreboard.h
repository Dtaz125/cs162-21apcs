#pragma once
#include <iostream>
using namespace std;
#include"Student.h"
#include "createNewCourse.h"

int GetIDcourse(Class& HCMUS, string id) {
    for (int i = 0; i < HCMUS.numcourse; i++) {
        if (HCMUS.course_list[i].id == id) return i;
    }
    return -1;
}

void viewScoreboardCourse(Class& HCMUS, Student& st) {
    system("cls");
    int id, baseX = 5, baseY = 1;

    system("cls");
    baseY = 1;
    drawText(posCenter("SCOREBOARD"), baseY, "--------------");
    drawText(posCenter("SCOREBOARD"), baseY + 1, "| SCOREBOARD |");
    drawText(posCenter("SCOREBOARD"), baseY + 2, "--------------");
    drawText(baseX, baseY + 4, "Student ID: "); cout << st.id;
    drawText(baseX, baseY + 5, "Full name: "); cout << st.user_info.firstname << " " << st.user_info.lastname;
    drawText(baseX, baseY + 6, "Class: "); cout << st.student_class;
    drawText(posCenter("ALL COURSES"), baseY + 7, "ALL COURSES");
    baseY += 8;
    drawText(baseX, baseY, "No");
    drawText(baseX + 8, baseY, "CourseID"); //cout << new_c.courseID[i];
    drawText(baseX + 23, baseY, "GPA"); //cout << new_c.maxstudent[i];
    drawText(baseX + 35, baseY, "Final"); //cout << new_c.curstudent[i];
    drawText(baseX + 50, baseY, "Midterm"); //if (avail[i]) cout << 1;
    drawText(baseX + 63, baseY, "Others"); //if (avail[i]) cout << 1;
    int d = 0;
    for (int i = 0; i < st.numcourse; i++) {
        baseY += 1;
        int index = GetIDcourse(HCMUS, st.list_of_courses[i].first);
        Course new_c;
        if (index == -1) {
            continue;
        }
        d++;
        new_c = HCMUS.course_list[index];
        drawText(baseX, baseY, to_string(d));
        drawText(baseX + 8, baseY, ""); cout << new_c.id;
        drawText(baseX + 23, baseY, "");
        if (new_c.is_published == false){
            cout << "the staff has't published this";
            continue;
        }
        Score sc;
        bool ok = false;
        travel(it, new_c.student_score){
            if ((*it).id == st.id) {
                sc = (*it);
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "doesn't have score results";
            continue;
        }
        cout << sc.final_mark;
        drawText(baseX + 35, baseY, ""); cout << sc.final_mark;
        drawText(baseX + 50, baseY, ""); cout << sc.midterm_mark;
        drawText(baseX + 63, baseY, "");
        for (int j = 0; j < sc.number_of_other_score; j++){
            cout << sc.other_score[j] << " ";
        }
    }
    _getch();
    system("cls");
}
