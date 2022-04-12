#pragma once
#include <iostream>
#include "other.h"
#include<sstream>
using namespace std;


#include "Student.h"
#include"Initialize.h"

void changeID(Student& st) {
    string new_ID;
    drawText(baseX, 3, "1. ID: " + blank);
    drawText(baseX, 3, "1. ID: ");
    cin >> new_ID;
     st.studentid = new_ID;
}

void changeName(Student& st) {
    string new_name;
    drawText(baseX, 4, "2. Full name: " + blank);
    drawText(baseX, 4, "2. Full name: ");
    cin.ignore();
    getline(cin, new_name);
    User tmp = st.user_info;
    int pos = -1;
    for (int i = new_name.size() - 1; i >= 0; i--) {
        if (new_name[i] == ' ') {
            pos = i;
            break;
        }
    }
    tmp.firstname = "";
    tmp.lastname = "";
    for (int i = 0; i < pos; i++)
        tmp.firstname += new_name[i];
    for (int i = pos + 1; i < new_name.size(); i++)
        tmp.lastname += new_name[i];

    st.user_info = tmp;
}

void changeBirthday(Student& st) {
    drawText(baseX, 5, "3. Birthday: " + blank);
    drawText(baseX, 5, "3. Birthday: ");
    cin.ignore();
    User info = st.user_info;
    string birth;
    getline(cin, birth);
    Date tmp;
    if (!validDate(birth, tmp)) return;
    info.birth = tmp;
    st.user_info = info;
}
void changeGender(Student& st) {
    string new_gen;
    drawText(baseX, 6, "4. Gender(Male/Female): " + blank);
    drawText(baseX, 6, "4. Gender(Male/Female): ");
    cin >> new_gen;
    User tmp = st.user_info;
    if (new_gen == "Male") tmp.gender = 0;
    else tmp.gender = 1;
    st.user_info = tmp;
}
void changeSocialID(Student& st) {
    string new_ID;
    drawText(baseX, 7, "5. Social ID: " + blank);
    drawText(baseX, 7, "5. Social ID: ");
    cin >> new_ID;
    User tmp = st.user_info;
    tmp.social_id = new_ID;
    st.user_info = tmp;
}

void viewClass(Student st) {
    system("cls");
    Class* new_class = st.student_class;
    drawText(baseX, 7, "Classname: " + new_class->name); cout << endl;
    drawText(baseX, 8, "Student list: "); cout << endl;
    int i = 9, index = 1;
    for (Iterator<Student> iter = new_class->student_list.begin(); iter != new_class->student_list.end(); iter++) {
        Student k = *iter;
        drawText(baseX + 1, i++, to_string(index) + ". " + k.user_info.firstname + " " + k.user_info.lastname); cout << endl;
        index++;
    }
    getch();
    system("cls");
}
void viewGPA(Student st) {

}

void changePassword(Student &st){
    string new_password;
    drawText(baseX, 9, "7. Change Password: ");
    cin >> new_password;
    st.password = new_password;
}

void viewListofCourse(Student st) {
    system("cls");
    int i = 7, index = 1;
    for (Iterator<Course> iter = st.list_of_courses.begin(); iter != st.list_of_courses.end(); iter++) {
        Course k = *iter;
        drawText(baseX, i++, to_string(index) + ". " + k.name + " | Teacher: " + k.teacher_name); cout << endl;
        index++;
    }
    getch();
    system("cls");
}

void drawStudentProfile(Student& st) {
    system("cls");
    int id;
    do {
        drawText(posCenter("Student Profile: "), 1, "Student Profile: ");
        drawText(baseX, 3, "1. ID: ");  cout << st.studentid;
        drawText(baseX, 4, "2. Full name: "); cout << st.user_info.firstname << " " << st.user_info.lastname;
        drawText(baseX, 5, "3. Birthday: "); cout << st.user_info.birth.day << "/" << st.user_info.birth.month << "/" << st.user_info.birth.year;
        drawText(baseX, 6, "4. Gender(Male/Female): "); cout << getGender(st);
        drawText(baseX, 7, "5. Social ID: "); cout << st.user_info.social_id;
        drawText(baseX, 8, "6. GPA: "); cout << st.gpa;
        drawText(baseX, 9, "7. Change Password: ");
        drawText(baseX, 10, "8. Class: ");
        drawText(baseX, 11, "9. List of course : ");
        drawText(baseX, 12, "10. Exit");
        drawText(posCenter("Press a number to change/view information: "), 13, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) {
            changeID(st);
        }
        else if (id == 2) { changeName(st); }
        else if (id == 3) { changeBirthday(st); }
        else if (id == 4) { changeGender(st); }
        else if (id == 5) { changeSocialID(st); }
        else if (id == 6) { viewGPA(st);}
        else if (id == 7) { changePassword(st);}
        else if (id == 8) { viewClass(st); }
        else if (id == 9) { viewListofCourse(st); }
        system("cls");
    } while (id != 10);
    system("cls");
}
