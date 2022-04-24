#pragma once
#include <iostream>
using namespace std;
#include"Student.h"
#include "createNewCourse.h"
int findCourse(Class& HCMUS, string id){
    for (int i = 0; i < HCMUS.numcourse; i++){
        if (HCMUS.course_list[i].id == id) return i;
    }
    return -1;
}

void viewCourse(Class& HCMUS, Student& st) {
system("cls");
    int id, baseX = 5, baseY = 1;

        system("cls");
        baseY = 1;
        drawText(posCenter("VIEW LIST OF COURSES"), baseY, "-----------------------");
        drawText(posCenter("VIEW LIST OF COURSES"), baseY + 1, "| VIEW LIST OF COURSES |");
        drawText(posCenter("VIEW LIST OF COURSES"), baseY + 2, "-----------------------");
        drawText(baseX, baseY + 4, "Student ID: "); cout << st.id;
        drawText(baseX, baseY + 5, "Full name: "); cout << st.user_info.firstname << " " << st.user_info.lastname;
        drawText(baseX, baseY + 6, "Class: "); cout << st.student_class;
        drawText(posCenter("ALL COURSES"), baseY + 7, "ALL COURSES");
        baseY += 8;
            drawText(baseX, baseY, "No");
            drawText(baseX + 13, baseY, "CourseID"); //cout << new_c.courseID[i];
            drawText(baseX + 29, baseY, "Course name"); //cout << new_c.maxstudent[i];
            drawText(baseX + 57, baseY, "Teacher"); //cout << new_c.curstudent[i];
            drawText(baseX + 70, baseY, "Teaching Time"); //if (avail[i]) cout << 1;
        int d = 0;
        for (int i = 0; i < st.numcourse; i++) {
            baseY += 1;
            int index = findCourse(HCMUS, st.list_of_courses[i].first);
            d++;
            Course new_c;
            if (index == -1) continue;
            new_c = HCMUS.course_list[index];
            drawText(baseX, baseY, to_string(d));
            drawText(baseX + 13, baseY, ""); cout << new_c.id;
            drawText(baseX + 29, baseY, ""); cout << new_c.name;
            drawText(baseX + 57, baseY, ""); cout << new_c.teacher_name;
            drawText(baseX + 70, baseY, ""); cout << convert_teachingtime(new_c.teaching_time);
        }
        getch();
        system("cls");
}
