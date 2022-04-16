#pragma once
#include <iostream>
#include "other.h"
#include<sstream>
#include "Student.h"
#include"Initialize.h"
using namespace std;

void changeID(Student& st) {
    string new_ID;
    drawText(baseX, 6, "1. ID: " + blank);
    drawText(baseX, 6, "1. ID: ");
    cin >> new_ID;
    st.studentid = new_ID;
}

void changeName(Student& st) {
    string new_name;
    drawText(baseX, 8, "2. Full name: " + blank);
    drawText(baseX, 8, "2. Full name: ");
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
    drawText(baseX, 10, "3. Birthday: " + blank);
    drawText(baseX, 10, "3. Birthday: ");
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
    drawText(baseX, 12, "4. Gender(Male/Female): " + blank);
    drawText(baseX, 12, "4. Gender(Male/Female): ");
    cin >> new_gen;
    User tmp = st.user_info;
    if (new_gen == "Male") tmp.gender = 0;
    else tmp.gender = 1;
    st.user_info = tmp;
}
void changeSocialID(Student& st) {
    string new_ID;
    drawText(baseX, 14, "5. Social ID: " + blank);
    drawText(baseX, 14, "5. Social ID: ");
    cin >> new_ID;
    User tmp = st.user_info;
    tmp.social_id = new_ID;
    st.user_info = tmp;
}

void viewGPA(Student st) {

}

void changePassword(Student& st) {
    string new_password;
    drawText(baseX, 18, "7. Change Password: ");
    cin >> new_password;
    st.password = new_password;
}


void drawStudentProfile(Student& st) {
    system("cls");
    int id, baseY=3;
    do {
        drawText(posCenter("STUDENT PROFILE"), baseY+1, "STUDENT PROFILE");
        drawText(baseX, baseY + 3, "1. ID: ");  cout << st.studentid;
        drawText(baseX, baseY + 5, "2. Full name: "); cout << st.user_info.firstname << " " << st.user_info.lastname;
        drawText(baseX, baseY + 7, "3. Birthday: "); cout << st.user_info.birth.day << "/" << st.user_info.birth.month << "/" << st.user_info.birth.year;
        drawText(baseX, baseY + 9, "4. Gender(Male/Female): "); cout << getGender(st);
        drawText(baseX, baseY + 11, "5. Social ID: "); cout << st.user_info.social_id;
        drawText(baseX, baseY + 13, "6. GPA: "); cout << st.gpa;
        drawText(baseX, baseY + 15, "7. Change Password: ");
        drawText(baseX, baseY + 17, "8. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 19, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) {
            changeID(st);
        }
        else if (id == 2) { changeName(st); }
        else if (id == 3) { changeBirthday(st); }
        else if (id == 4) { changeGender(st); }
        else if (id == 5) { changeSocialID(st); }
        else if (id == 6) { viewGPA(st); }
        else if (id == 7) { changePassword(st); }
        system("cls");
    } while (id != 8);
    system("cls");
}
