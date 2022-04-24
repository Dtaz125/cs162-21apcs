#pragma once
#include"Staff.h"
#include"Initialize.h"
#include"other.h"
#include"Link.h"

void findCourse(Link& link) {
    system("cls");
    int id, baseY=3;
    do {
        drawText(posCenter("VIEW COURSE SCOREBOARD"), baseY, "--------------------------");
        drawText(posCenter("VIEW COURSE SCOREBOARD"), baseY + 1, "| COURSE SCOREBOARD |");
        drawText(posCenter("VIEW COURSE SCOREBOARD"), baseY + 2, "--------------------------");
        drawText(baseX, baseY + 3, "1. School Year: "); cout << link.year;
        drawText(baseX, baseY + 5, "2. Semester: "); cout << link.semester;
        drawText(baseX, baseY + 7, "3. Course ID: "); cout << link.courseID;
        drawText(baseX, baseY + 9, "4. Continue: ");
        drawText(baseX, baseY + 11, "5. Exit: ");
        drawText(posCenter("Press a number to change/view information: "), baseY + 13, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) changeYear(link, baseX, baseY+3, "1. School Year: ");
        else if (id == 2) { changeSemester(link, baseX, baseY + 5, "2. Semester: "); }
        else if (id == 3) { changeCourseID(link, baseX, baseY + 7, "3. Course ID: "); }
        else if (id == 4){

        }
        system("cls");
    } while (id != 5);
    system("cls");
}

string generateGPA(string id_student, Class& tmp) {
    float gpa, count = 0;
    for (int i = 0; i < tmp.student_list.size(); i++) {
        Node<Student>* stu = tmp.student_list[i];
        if (id_student == stu->data.id) {
            for (int j = 0; j < stu->data.numcourse; j++) {
                
            }
            break;
        }
    }
}
void displayClass(string Folder, Link& link) {
    float count = 0.0;
    Class curr, tmp;
    curr.name = link.classname;
    inputClassData(Folder, curr);
    inputStudentData(tmp);
    system("cls");
    int id;
    do {
        drawText(posCenter("CLASS SCOREBOARD"), baseY, "--------------------");
        drawText(posCenter("CLASS SCOREBOARD"), baseY + 1, "| CLASS SCOREBOARD |");
        drawText(posCenter("CLASS SCOREBOARD"), baseY + 2, "--------------------");
        drawText(baseX - 20, baseY + 3, "ID\t\t\t\tFull name\t\t\t\tOverall GPA");
        for (int i = 0; i < curr.student_list.size(); i++) {
            Node<Student>* cur = curr.student_list[i];
            for (int j = 0; j < tmp.student_list.size(); j++) {
                Node<Student>* k = tmp.student_list[i];
                if (cur->data.id == k->data.id) {
                    drawText(baseX - 20, baseY + 4 + 2 * i, cur->data.id + "\t\t\t" + cur->data.user_info.firstname + " " + cur->data.user_info.lastname + "\t\t\t\t" + to_string(calculateGPA(k->data, count)));
                    break;
                }
            }
        }
        drawText(posCenter("Press 1 to exit: "), baseY + 4 + 2* curr.student_list.size(), "Press 1 to exit: ");
        cin >> id;
        system("cls");
    } while (id != 1);
    system("cls");
}

void findClass(Link& link) {
    system("cls");
    int id;
    do {
        drawText(posCenter("CLASS SCOREBOARD"), baseY, "--------------------");
        drawText(posCenter("CLASS SCOREBOARD"), baseY + 1, "| CLASS SCOREBOARD |");
        drawText(posCenter("CLASS SCOREBOARD"), baseY + 2, "--------------------");
        drawText(baseX, baseY + 3, "1. School Year: "); cout << link.year;
        drawText(baseX, baseY + 5, "2. Class: "); cout << link.classname;
        drawText(baseX, baseY + 7, "3. Continue");
        drawText(baseX, baseY + 9, "4. Exit: ");
        drawText(posCenter("Press a number to change/view information: "), baseY + 11, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) changeYear(link, baseX, baseY + 3, "1. School Year: ");
        else if (id == 2) { changeClass(link, baseX, baseY + 5, "2. Class: "); }
        else if (id == 3) {
            string Folder = "system/schoolyears/" + link.year + "/classes";
            displayClass(Folder, link);
        }
        system("cls");
    } while (id != 4);
    system("cls");
}

void viewScoreBoard(const Staff& st) {
    system("cls");
    int id;
    Link link;
    do {
        drawText(posCenter("VIEW SCOREBOARD"), baseY, "-------------------");
        drawText(posCenter("VIEW SCOREBOARD"), baseY + 1, "| VIEW SCOREBOARD |");
        drawText(posCenter("VIEW SCOREBOARD"), baseY + 2, "-------------------");
        drawText(baseX, baseY + 3, "1. Course");
        drawText(baseX, baseY + 5, "2. Class");
        drawText(baseX, baseY + 7, "3. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 9, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) findCourse(link);
        else if (id == 2) { findClass(link); }
        system("cls");
    } while (id != 3);
    system("cls");
}
