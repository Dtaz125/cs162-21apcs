#pragma once

#include<iostream>
using namespace std;

void testDataFunction(Class& HCMUS){
    inputAllData(HCMUS);
    travel(it, HCMUS.staff_list){
        cout << (*it).id << " " << (*it).username << " " << (*it).password << endl;
    }
    //outputStaffData(HCMUS);
}
