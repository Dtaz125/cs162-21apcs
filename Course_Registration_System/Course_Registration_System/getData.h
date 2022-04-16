#pragma once
#include <iostream>
using namespace std;

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

void getProfile(Staff& st, string id){
    string userFile = "system/staffs/staffs.txt";
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
