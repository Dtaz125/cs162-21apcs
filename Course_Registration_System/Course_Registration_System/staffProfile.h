#pragma once
#include <iostream>
#include"Initialize.h"
#include"other.h"
using namespace std;

//const int baseX = 30;
//const string blank = "                                                     ";
#include "Staff.h"
/*struct Staff{
    string name = "Vinh";
    string id = "21125030";
    string gender = "Male";
    string socialID = "192108211";
};*/

string getGender(Staff st) {
    if (st.getInfo().gender == 0) return "Male";
    return "Female";
}

void changeName(Staff& st) {
    string new_name;
    drawText(baseX, 4, "1. Full name: " + blank);
    drawText(baseX, 4, "1. Full name: ");
    cin.ignore();
    getline(cin, new_name);
    User tmp = st.getInfo();
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

    st.setInfo(tmp);
}

void changeBirthday(Staff& st) {
    drawText(baseX, 5, "2. Birthday: " + blank);
    drawText(baseX, 5, "2. Birthday: ");
    cin.ignore();
    User info = st.getInfo();
    string birth;
    getline(cin, birth);
    if (!validDate(birth, info.birth)) return;
    st.setInfo(info);
}
void changeGender(Staff& st) {
    string new_gen;
    drawText(baseX, 6, "3. Gender(Male/Female): " + blank);
    drawText(baseX, 6, "3. Gender(Male/Female): ");
    cin >> new_gen;
    User tmp = st.getInfo();
    if (new_gen == "Male") tmp.gender = 0;
    else tmp.gender = 1;
    st.setInfo(tmp);
}
void changeSocialID(Staff& st) {
    string new_ID;
    drawText(baseX, 7, "4. Social ID: " + blank);
    drawText(baseX, 7, "4. Social ID: ");
    cin >> new_ID;
    User tmp = st.getInfo();
    tmp.social_id = new_ID;
    st.setInfo(tmp);
}
void viewClass(Staff st) {

}
void viewGPA(Staff st) {}
void viewListofCourse(Staff st) {

}

void drawStaffProfile(Staff& st)
{
    system("cls");
    int id;
    do {
        drawText(posCenter("Staff Profile: "), 1, "Staff Profile: ");
        drawText(baseX, 4, "1. Full name: "); cout << st.getInfo().firstname << " " << st.getInfo().lastname;
        drawText(baseX, 5, "2. Birthday: "); cout << st.getInfo().birth.day << "/" << st.getInfo().birth.month << "/" << st.getInfo().birth.year;
        drawText(baseX, 6, "3. Gender(Male/Female): "); cout << getGender(st);
        drawText(baseX, 7, "4. Social ID: "); cout << st.getInfo().social_id;
        drawText(baseX, 8, "5. Class: ");
        drawText(baseX, 9, "6. List of course : ");
        drawText(baseX, 10, "7. Exit");
        drawText(posCenter("Press a number to change/view information: "), 12, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeName(st); }
        else if (id == 2) { changeBirthday(st); }
        else if (id == 3) { changeGender(st); }
        else if (id == 4) { changeSocialID(st); }
        else if (id == 5) { viewClass(st); }
        else if (id == 6) { viewListofCourse(st); }
        system("cls");
    } while (id != 9);
    system("cls");
}