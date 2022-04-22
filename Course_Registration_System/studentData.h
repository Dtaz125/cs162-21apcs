#pragma once
#include <iostream>
#include "Class.h"
using namespace std;

void outputStudentData(Class &HCMUS){
    string accFile = "system/students/accounts.txt";
    string userFile = "system/students/students.txt";
    ofstream user(userFile);
    ofstream acc(accFile);
    Student st;
    User info;
    travel(it, HCMUS.student_list){
        st = (*it);
        info = st.user_info;
        acc << st.id << endl << st.username << endl << st.password << endl;
        user << st.id << endl << info.firstname << " " << info.lastname << endl;
        user << st.user_info.birth.day << "/" << st.user_info.birth.month << "/" << st.user_info.birth.year << endl;
        user << info.gender << endl << info.social_id << endl;
    }
    acc.close();
    user.close();
}

void inputStudentData(Class &HCMUS){
    HCMUS.student_list.empty_list();
    string accFile = "system/students/accounts.txt";
    string userFile = "system/students/students.txt";
    ifstream user(userFile);
    ifstream acc(accFile);
    /// open File
    string cur_id, us, pass;
    string gender, fullName, birth, socialID;
    ///
    while (getline(user, cur_id)){
        Student st;
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
        HCMUS.student_list.add(st);
        //cout << cur_id << " " << HCMUS.student_list.size() << endl;

    }
    user.close();
    acc.close();
}

void getProfile(Student& st, string id){
    string userFile = "system/students/students.txt";
    ifstream user(userFile);
    /// open File
    string cur_id, us, pass;
    string gender, fullName, birth, socialID;
    ///
    while (!user.eof()){
        /// search for accounts
        getline(user, cur_id, '\n');
        getline(user, fullName, '\n');
        getline(user, birth, '\n');
        getline(user, gender, '\n');
        getline(user, socialID, '\n');
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

void outputStudent(Student& st, string id){
    string userFile = "system/students/students.txt";
    ofstream user(userFile, ios::app);
    user << st;
    user.close();
}
