#pragma once
#include"Initialize.h"
#include"other.h"
#include"Staff.h"
#include"Link.h"
void deleteCourse(Semester& st) {
    int id, baseY = 3;
    Link link;
    do {
        system("cls");
        drawText(posCenter("DELETE COURSE"), baseY, "--------------");
        drawText(posCenter("DELETE COURSE"), baseY + 1, "| DELETE COURSE |");
        drawText(posCenter("DELETE COURSE"), baseY + 2, "--------------");
        drawText(baseX, baseY + 3, "1. Course ID: "); cout << link.courseID;
        drawText(baseX, baseY + 5, "2. Delete");
        drawText(baseX, baseY + 7, "3. Exit");
        //display course have created here
        drawText(posCenter("Press a number to change/view information: "), baseY + 9, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeCourseID (link, baseX, baseY + 3, "1. Course ID: "); }
        else if (id == 2){
            //do something hereif
            for (int i = 0; i < st.list_of_courses.size(); i++){
                auto& p = st.list_of_courses[i]->data;
                if (p.first == link.courseID){
                    p = {"", ""};
                }
            }
        }
        system("cls");
    } while (id != 3);
}

