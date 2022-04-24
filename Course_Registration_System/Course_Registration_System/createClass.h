#pragma once
#include"Staff.h"
#include"other.h"
#include"Initialize.h"
#include"SchoolYear.h"
#include"Class.h"
#include"classData.h"
#include"Staff.h"
#include"Link.h"
void createClass(SchoolYear& st) {
    system("cls");
    int id, baseY = 3;
    Link link;
    do {
        drawText(posCenter("CLASS"), baseY, "---------");
        drawText(posCenter("CLASS"), baseY + 1, "| CLASS |");
        drawText(posCenter("CLASS"), baseY + 2, "---------");
        drawText(baseX, baseY + 4, "1. Name: "); cout << link.classname;
        drawText(baseX, baseY + 6, "2. Link Students CSV: "); cout << link.link;
        drawText(baseX, baseY + 8, "3. Create");
        drawText(baseX, baseY + 10, "4. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 12, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeClass(link, baseX, baseY + 4, "1. Name: "); }
        else if (id == 2) { changeLinkCSV(link, baseX, baseY + 6, "2. Link Students CSV: "); }
        else if (id == 3) {
            Class curr;
            string Folder = "system/schoolyears/" + st.name + "/classes";
            curr.name = link.classname;
            outputClassData(Folder, curr);
            readCSV(curr, link.link);
            outputClassData(Folder, curr);
        }
        system("cls");
    } while (id != 4);
    system("cls");
}
void updateStudent(Link& link, SchoolYear& st) {
    Class curr, new_class;
    curr.name = link.classname;
    new_class.name = link.classname_1;
    string Folder = "system/schoolyears/" + st.name + "/classes";
    inputClassData(Folder, curr);
    inputClassData(Folder, new_class);
    /*Student tmp; tmp.id = link.studentID;
    tmp = curr.student_list.contains(tmp)->data;
    curr.student_list.remove(tmp);
    new_class.student_list.add(tmp);
    outputClassData(Folder, new_class);*/
}
void changeClass(SchoolYear& st) {
    system("cls");
    int id, baseY = 3;
    Link link;
    do {
        drawText(posCenter("CLASS"), baseY, "----------------");
        drawText(posCenter("CLASS"), baseY + 1, "| CHANGE CLASS |");
        drawText(posCenter("CLASS"), baseY + 2, "----------------");
        drawText(baseX, baseY + 4, "1. Student ID: "); cout << link.studentID;
        drawText(baseX, baseY + 6, "2. Old Class: "); cout << link.classname;
        drawText(baseX, baseY + 8, "3. New Class: "); cout << link.classname_1;
        drawText(baseX, baseY + 10, "4. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 12, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeStudentID(link, baseX, baseY + 4, "1. Student ID: "); }
        else if (id == 2) { changeClass(link, baseX, baseY + 6, "2. Old Class: "); }
        else if (id == 3) {
            changeClass_1(link, baseX, baseY + 8, "3. New Class: ");
            
            
            link = { "",0,"", "", "", "","Change has been made." };
        }
        system("cls");
    } while (id != 4);
    system("cls");
}

void modifyClass(SchoolYear& st) {
    system("cls");
    int id, baseY = 3;
    do {
        drawText(posCenter("CLASS"), baseY, "---------");
        drawText(posCenter("CLASS"), baseY + 1, "| CLASS |");
        drawText(posCenter("CLASS"), baseY + 2, "---------");
        drawText(baseX, baseY + 4, "1. Create");
        drawText(baseX, baseY + 6, "2. Modify");
        drawText(posCenter("Press a number to change/view information: "), baseY + 8, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { createClass(st); }
        else if (id == 2) { changeClass(st); }
        system("cls");
    } while (id != 3);
    system("cls");
}