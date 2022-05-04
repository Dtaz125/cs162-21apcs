#pragma once
#include"Student.h"
#include"other.h"
#include"Link.h"

string generateCourseAttending(string id_student, Class& tmp) {
    string s = "";
    for (int i = 0; i < tmp.student_list.size(); i++) {
        Node<Student>* stu = tmp.student_list[i];
        if (id_student == stu->data.id) {
            for (int j = 0; j < stu->data.numcourse; j++) {
                s += stu->data.list_of_courses[j].first + " ";
            }
            break;
        }
    }
    return s;
}

void showClass(Student& st, Link& link) {
    system("cls");
    int baseY = 3, id;
    Class tmp, tmp_1;
    tmp.name = st.student_class;
    string Folder = "system/schoolyears/" + link.year + "/classes";
    inputClassData(Folder, tmp);
    inputStudentData(tmp_1);
    do {
        system("cls");
        drawText(posCenter("YOUR CLASS"), baseY, "--------------");
        drawText(posCenter("YOUR CLASS"), baseY + 1, "| YOUR CLASS |");
        drawText(posCenter("YOUR CLASS"), baseY + 2, "--------------");
        drawText(baseX - 20, baseY + 3, "ID\t\t\t\tFull name\t\t\t\tCourse Attending");
        for (int i = 0; i < tmp.student_list.size(); i++) {
            Node<Student>* curr = tmp.student_list[i];
            drawText(baseX - 20, baseY + 4 + 2*i, curr->data.id + "\t\t\t" + curr->data.user_info.firstname + " " + curr->data.user_info.lastname + "\t\t\t\t" + generateCourseAttending(curr->data.id, tmp_1));
        }
        drawText(posCenter("Press number 1 to exit: "), baseY + 4 + 2*tmp.student_list.size(), "Press number 1 to exit:  ");
        cin >> id;
    } while (id!=1);
        
}

void viewClass(Student& st) {
    system("cls");
    int baseY = 3, id;
    Link link;
    do {
        system("cls");
        drawText(posCenter("YOUR CLASS"), baseY, "--------------");
        drawText(posCenter("YOUR CLASS"), baseY + 1, "| YOUR CLASS |");
        drawText(posCenter("YOUR CLASS"), baseY + 2, "--------------");
        drawText(baseX, baseY + 3, "1. Year: "); cout << link.year;
        drawText(baseX, baseY + 5, "2. Next");
        drawText(baseX, baseY + 7, "3. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 9, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) changeYear(link, baseX, baseY + 3, "1. Year: ");
        else if (id == 2) showClass(st, link);
        system("cls");
    } while (id!=3);
}