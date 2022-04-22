#pragma once
#include <iostream>
void outputStaffData(Class &HCMUS){
    string accFile = "system/staffs/accounts.txt";
    string userFile = "system/staffs/staffs.txt";
    ofstream user(userFile);
    ofstream acc(accFile);
    travel(it, HCMUS.staff_list){
        Staff st = (*it);
        User info = st.user_info;
        acc << st.id << endl << st.username << endl << st.password << endl;
        user << st.id << endl << info.firstname << " " << info.lastname << endl;
        user << st.user_info.birth.day << "/" << st.user_info.birth.month << "/" << st.user_info.birth.year << endl;
        user << info.gender << endl << info.social_id << endl;
    }
    acc.close();
    user.close();
}

void inputStaffData(Class &HCMUS){
    HCMUS.staff_list.empty_list();
    string accFile = "system/staffs/accounts.txt";
    string userFile = "system/staffs/staffs.txt";
    ifstream user(userFile);
    ifstream acc(accFile);
    /// open File
    string cur_id, us, pass;
    string gender, fullName, birth, socialID;
    ///
    while (getline(user, cur_id)){
        Staff st;
        /// search for accounts
        getline(user, fullName);
        getline(user, birth);
        getline(user, gender);
        getline(user, socialID);
        getline(acc, cur_id);
        getline(acc, us);
        getline(acc, pass);
        changeID(st, cur_id);
        changeName(st, fullName);
        changeBirthday(st, birth);
        changeGender(st, gender);
        changeSocialID(st, socialID);
        changeUsername(st, us);
        changePassword(st, pass);
        //cout << st.id << " " << st.username << " " << st.password << endl;
        HCMUS.staff_list.add(st);
        //cout << cur_id << " " << HCMUS.staff_list.size() << endl;

    }
    user.close();
    acc.close();
}

void getProfile(Staff& st, string id){
    string userFile = "system/staffs/staffs.txt";
    ifstream user(userFile);
    /// open File
    string cur_id, us, pass;
    string gender, fullName, birth, socialID;
    ///
    while (!user.eof()){
        /// search for accounts
        getline(user, cur_id);
        getline(user, fullName);
        getline(user, birth);
        getline(user, gender);
        getline(user, socialID);
        if (id == cur_id) {
            changeID(st, cur_id);
            changeName(st, fullName);
            changeBirthday(st, birth);
            changeGender(st, gender);
            changeSocialID(st, socialID);
            break;
        }
    }
    user.close();
}
