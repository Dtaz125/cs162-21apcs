#pragma once
#include <iostream>
#include"Initialize.h"
#include"other.h"
using namespace std;

#include "Staff.h"

string getGender(Staff& st) {
    if (st.user_info.gender == 0) return "Male";
    return "Female";
}

void changeName(Staff& st) {
    string new_name;
    drawText(baseX, baseY + 0, "1. Full name: " + blank);
    drawText(baseX, baseY + 0, "1. Full name: ");
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

void changeBirthday(Staff& st) {
    drawText(baseX, baseY + 2, "2. Birthday: " + blank);
    drawText(baseX, baseY + 2, "2. Birthday: ");
    cin.ignore();
    User info = st.user_info;
    string birth;
    getline(cin, birth);
    if (!validDate(birth, info.birth)) return;
    st.user_info = info;
}
void changeGender(Staff& st) {
    string new_gen;
    drawText(baseX, baseY + 5, "3. Gender(Male/Female): " + blank);
    drawText(baseX, baseY + 5, "3. Gender(Male/Female): ");
    cin >> new_gen;
    User tmp = st.user_info;
    if (new_gen == "Male") tmp.gender = 0;
    else tmp.gender = 1;
    st.user_info = tmp;
}
void changeSocialID(Staff& st) {
    string new_ID;
    drawText(baseX, baseY + 6, "4. Social ID: " + blank);
    drawText(baseX, baseY + 6, "4. Social ID: ");
    cin >> new_ID;
    User tmp = st.user_info;
    tmp.social_id = new_ID;
    st.user_info = tmp;
}
void viewClass(Staff st) {

}

void viewListofCourse(Staff& st) {

}

void changePassword(Staff& st) {
    string new_password;
    drawText(baseX, baseY + 8, "5. Change Password: ");
    cin >> new_password;
    st.password = new_password;
}

void drawStaffProfile(Staff& st)
{
    system("cls");
    int id, baseY=3;
    do {
        drawText(posCenter("STAFF PROFILE"), baseY, "-----------------");
        drawText(posCenter("STAFF PROFILE"), baseY + 1, "| STAFF PROFILE |");
        drawText(posCenter("STAFF PROFILE"), baseY + 2, "-----------------");
        drawText(baseX, baseY + 4, "1. Full name: "); cout << st.user_info.firstname << " " << st.user_info.lastname;
        drawText(baseX, baseY + 6, "2. Birthday: "); cout << st.user_info.birth.day << "/" << st.user_info.birth.month << "/" << st.user_info.birth.year;
        drawText(baseX, baseY + 8, "3. Gender(Male/Female): "); cout << getGender(st);
        drawText(baseX, baseY + 10, "4. Social ID: "); cout << st.user_info.social_id;
        drawText(baseX, baseY + 12, "5. Change Password: ");
        drawText(baseX, baseY + 14, "6. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY+16, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeName(st); }
        else if (id == 2) { changeBirthday(st); }
        else if (id == 3) { changeGender(st); }
        else if (id == 4) { changeSocialID(st); }
        else if (id == 5) { changePassword(st); }
        system("cls");
    } while (id != 6);
    system("cls");
}
