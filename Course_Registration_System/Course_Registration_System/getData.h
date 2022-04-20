#pragma once
#include "Class.h"
#include "staffData.h"
#include <iostream>
using namespace std;

void updateClass(Class& HCMUS, Staff st){
    for (int i = 0; i < HCMUS.staff_list.size(); i++){
        string id = HCMUS.staff_list[i]->data.id;
        if (id == st.id){
            HCMUS.staff_list[i]->data = st;
            return;
        }
    }
}

void inputAllData(Class& HCMUS){
    inputStaffData(HCMUS);
}

