#pragma once
#include"Staff.h"
#include"other.h"
#include"Initialize.h"
void printCourseStatus(bool is_pub){
    if (is_pub) cout << "published";
    else cout << "unpublished";
}
void publishCourse(Class& HCMUS, Staff& st) {
    int baseY = 3, id;
    int curCourse = -1;
    Link link;
    do {
        system("cls");
        drawText(posCenter("PUBLISHING COURSE"), baseY, "---------------------");
        drawText(posCenter("PUBLISHING COURSE"), baseY + 1, "| PUBLISHING COURSE |");
        drawText(posCenter("PUBLISHING COURSE"), baseY + 2, "---------------------");
//        drawText(baseX, baseY + 4, "1. School Year: "); cout << link.year;
//        drawText(baseX, baseY + 6, "2. Semester: "); cout << link.semester;
        drawText(baseX, baseY + 4, "1. Course ID: "); cout << link.courseID;
        drawText(baseX, baseY + 6, "2. Publish: ");
            if (curCourse < 0) cout << "Can't find this course";
            else printCourseStatus(HCMUS.course_list[curCourse].is_published);
        drawText(baseX, baseY + 8, "3. Exit: ");
        drawText(posCenter("Press a number: : "), baseY + 10, "Press a number: : ");

        cin >> id;


        //if (id == 1) changeYear(link, baseX, baseY + 4, "1. School Year: "); //done
        //else if (id == 2) changeSemester(link, baseX, baseY + 6, "2. Semester: "); //done
        if (id == 1) {
            changeCourseID(link, baseX, baseY + 4, "1. Course ID: "); //done
            curCourse = -1;
            travelCourse(it){
                if (HCMUS.course_list[it].id == link.courseID){
                    curCourse = it;
                    break;
                }
            }
        }
        else if (id == 2) {
            if (curCourse == -1) continue;
            //do something here
            drawText(baseX, baseY + 6, blank);
            drawText(baseX, baseY + 6, "2. Input publish status[0/1]: ");
            cin >> HCMUS.course_list[curCourse].is_published;
            outputCourseData(HCMUS);
        }
        else {
            system("cls");
            return;
        }
    } while (id != 5);
}
