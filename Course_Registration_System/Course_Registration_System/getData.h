#pragma once
#include "Class.h"
#include "staffData.h"
#include "studentData.h"
#include <iostream>
using namespace std;

void updateClass(Class& HCMUS, Staff st){
    for (int i = 0; i < HCMUS.staff_list.size(); i++){
        string username= HCMUS.staff_list[i]->data.username;
        if (username == st.username){
            HCMUS.staff_list[i]->data = st;
            return;
        }
    }
}

void updateClass(Class& HCMUS, Student& st){
    for (int i = 0; i < HCMUS.student_list.size(); i++){
        string username = HCMUS.student_list[i]->data.username;
        if (username == st.username){
            HCMUS.student_list[i]->data = st;
            return;
        }
    }
}

void inputAllData(Class& HCMUS){
    inputStaffData(HCMUS);
    inputStudentData(HCMUS);
}

