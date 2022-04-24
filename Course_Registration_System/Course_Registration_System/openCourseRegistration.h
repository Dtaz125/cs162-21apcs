#pragma once
#include <iostream>
#include"Student.h"
#include"Staff.h"
#include"Initialize.h"
#include"other.h"
#include"CourseRegistration.h"
#include"CourseRegistrationData.h"
using namespace std;

bool Matched(string cID, Student st){
    for (int i = 0; i < st.numcourse; i++) if (cID == st.list_of_courses[i].first)
        return true;
    return false;
}

string getCourseName(Class& HCMUS, string id){
    travelCourse(it){
        if (HCMUS.course_list[it].id == id)
            return HCMUS.course_list[it].name;
    }
    return id;
}

void drawOpenCourse(Class& HCMUS, Student& st) {
    system("cls");
    int id, baseX = 5, baseY = 1;
    CourseRegistration new_c;
    bool *avail;
    do {
        system("cls");
        baseY = 1;
        drawText(posCenter("COURSE REGISTRATION"), baseY, "-----------------------");
        drawText(posCenter("COURSE REGISTRATION"), baseY + 1, "| COURSE REGISTRATION |");
        drawText(posCenter("COURSE REGISTRATION"), baseY + 2, "-----------------------");
        drawText(baseX, baseY + 4, "1. School year: "); cout << new_c.syear;
        drawText(baseX, baseY + 5, "2. Semester: "); cout << new_c.semester;
        drawText(baseX, baseY + 6, "   Start Date: "); cout << new_c.start_date.day << "/" << new_c.start_date.month << "/" << new_c.start_date.year;
        drawText(baseX, baseY + 7, "   End Date: "); cout << new_c.end_date.day << "/" << new_c.end_date.month << "/" << new_c.end_date.year;
        drawText(baseX, baseY + 8, "3. Register: ");
        drawText(baseX, baseY + 9, "4. Exit: ");
        drawText(posCenter("ALL COURSES"), baseY + 10, "ALL COURSES");
        baseY += 12;
            drawText(baseX, baseY, "No");
            drawText(baseX + 15, baseY, "CourseID"); //cout << new_c.courseID[i];
            drawText(baseX + 35, baseY, "Max Student"); //cout << new_c.maxstudent[i];
            drawText(baseX + 60, baseY, "Cur Student"); //cout << new_c.curstudent[i];
            drawText(baseX + 83, baseY, "Status"); //if (avail[i]) cout << 1;
        for (int i = 0; i < new_c.numcourse; i++) {
            baseY += 1;
            drawText(baseX, baseY, to_string(i + 1));
            drawText(baseX + 15, baseY, ""); cout << new_c.courseID[i];
            drawText(baseX + 35, baseY, ""); cout << new_c.maxstudent[i];
            drawText(baseX + 60, baseY, ""); cout << new_c.curstudent[i];
            drawText(baseX + 83, baseY, ""); if (avail[i]) cout << "Registered";
        }

        drawText(baseX, baseY + 4, blank);
        drawText(posCenter("Input number to change/modify: "), baseY + 4, "Input number to change/modify: ");
        cin >> id;

        if (id == 1) {
            baseY = 1;
            changeSchoolyear(new_c, baseX, baseY + 4, "1. School year: ");
            inputRegisData(new_c, new_c.syear, new_c.semester);
            avail = new bool[new_c.numcourse + 5];
            for (int i = 0; i < new_c.numcourse; i++){
                avail[i] = Matched(new_c.courseID[i], st);
            }
        }
        else if (id == 2) {
            baseY = 1;
            changeSemester(new_c, baseX, baseY + 5, "2. Semester: ");
            inputRegisData(new_c, new_c.syear, new_c.semester);
            avail = new bool[new_c.numcourse];
            for (int i = 0; i < new_c.numcourse; i++){
                avail[i] = Matched(new_c.courseID[i], st);
            }
        }
        else if (id == 3) {
            drawText(baseX, baseY + 4, blank);
            drawText(posCenter("Input index of courseID to register: "), baseY + 4, "Input index of courseID to register: ");
            int index; cin >> index;
            if (index <= 0 || index > new_c.numcourse){
                continue;
            }
            if (!avail[index - 1]){
                if (!new_c.addStudent(index - 1, st.id, st.user_info.firstname + " " + st.user_info.lastname)){
                    drawText(posCenter("This course is full"), baseY + 5, "This course is full");
                }
                else{
                    avail[index - 1] = true;
                    if (st.addCourse(new_c.courseID[index - 1], getCourseName(HCMUS, new_c.courseID[index - 1]))){
                        updateClass(HCMUS, st);
                        outputStudentData(HCMUS);
                    }
                    outputRegisData(new_c);
                }
            }
        }
        else if (id == 4) {


        }
        else if (id == 5) {

        }

        system("cls");
    } while (id != 4);
}

void drawOpenCourse(const Staff& st) {
    int id, baseY = 3;
    CourseRegistration new_c;
    do {
        drawText(posCenter("CREATE COURSE REGISTRATION"), baseY, "------------------------------");
        drawText(posCenter("CREATE COURSE REGISTRATION"), baseY + 1, "| CREATE COURSE REGISTRATION |");
        drawText(posCenter("CREATE COURSE REGISTRATION"), baseY + 2, "------------------------------");
        drawText(baseX, baseY + 4, "1. School year: "); cout << new_c.syear;
        drawText(baseX, baseY + 6, "2. Semester: "); cout << new_c.semester;
        drawText(baseX, baseY + 8, "3. Start Date: "); cout << new_c.start_date.day << "/" << new_c.start_date.month << "/" << new_c.start_date.year;
        drawText(baseX, baseY + 10, "4. End Date: "); cout << new_c.end_date.day << "/" << new_c.end_date.month << "/" << new_c.end_date.year;
        drawText(baseX, baseY + 12, "5. Add courseID: ");
        for (int i = 0; i < new_c.numcourse; i++) cout << new_c.courseID[i] << ", ";
        drawText(baseX, baseY + 14, "   Max student of course: ");
        drawText(baseX, baseY + 16, "6. Cancel: ");
        drawText(posCenter("Press a number to change/view information: "), baseY + 18, "Press a number to change/view information: ");
        cin >> id;

        if (id == 1) { changeSchoolyear(new_c, baseX, baseY + 4, "1. School year: "); }
        else if (id == 2) { changeSemester(new_c, baseX, baseY + 6, "2. Semester: "); }
        else if (id == 3) {
            changeStartDate(new_c, baseX, baseY + 8, "3. Start Date: ");
            outputRegisData(new_c);
        }
        else if (id == 4) {
            changeEndDate(new_c, baseX, baseY + 10, "4. End Date: ");
            outputRegisData(new_c);
        }
        else if (id == 5) {
            addCourse(new_c, baseX, baseY + 12, "5. Add courseID: ", "  Max student of course: ");
            //do something here
            outputRegisData(new_c);
        }
        inputRegisData(new_c, new_c.syear, new_c.semester);
        system("cls");
    } while (id != 6);
}
