#pragma once
#include <iostream>
#include<string>
#include "Date.h"
#include "Staff.h"
using namespace std;
const int baseY = 7;
const int baseX = 30;
const string blank = "                                                     ";
string getGender(auto& st) {
    if (st.user_info.gender == 0) return "Male";
    else return "Female";
}

bool isdigit(char ch) {
    return '0' <= ch && ch <= '9';
}

bool validDate(string birth, Date& dt) {
    for (int i = 0; i < birth.size(); i++) {
        char ch = birth[i];
        if (!isdigit(ch) && ch != ' ' && ch != '/')
            return false;
        if (ch == ' ' || ch == '/') {
            if (i == 0 || i == birth.size() - 1) return false;
            if (!isdigit(birth[i - 1]) || !isdigit(birth[i + 1])) return false;
        }
    }
    int iter = 0;
    dt.day = dt.month = dt.year = 0;
    while (iter < birth.size() && dt.day <= 31) {
        if (isdigit(birth[iter])) {
            dt.day = dt.day * 10 + birth[iter++] - '0';
            if (dt.day >= 100) {
                dt.day /= 10;
                iter--;
                break;
            }
        }
        else {
            iter++;
            break;
        }
    }
    while (iter < birth.size() && dt.month <= 12) {
        if (isdigit(birth[iter])) {
            dt.month = dt.month * 10 + birth[iter++] - '0';
            if (dt.month >= 100) {
                dt.month /= 10;
                iter--;
                break;
            }
        }
        else {
            iter++;
            break;
        }
    }
    while (iter < birth.size()) {
        if (isdigit(birth[iter]))
            dt.year = dt.year * 10 + birth[iter++] - '0';
        else {
            iter++;
            break;
        }
    }
    if (dt.day > 31 || dt.month > 12 || dt.day == 0 || dt.month == 0) return false;
    return true;
}

void changeID(Student &st, string new_ID){
    st.id = new_ID;
}

void changeID(Staff &st, string new_ID){
    st.id = new_ID;
}

void changeName(auto& st, string new_name) {
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
void changeBirthday(auto& st, string birth) {
    User info = st.user_info;
    if (!validDate(birth, info.birth)) return;
    st.user_info = info;
}
void changeGender(auto& st, bool gender) {
    User tmp = st.user_info;
    tmp.gender = gender;
    st.user_info = tmp;
}

void changeGender(auto& st, string gender) {
    if (gender == "0") changeGender(st, 0);
    else changeGender(st, 1);
}

void changeSocialID(auto& st, string new_ID) {
    User tmp = st.user_info;
    tmp.social_id = new_ID;
    st.user_info = tmp;
}

void changeUsername(auto &st, string username){
    st.username = username;
}

void changePassword(auto &st, string password){
    st.password = password;
}
