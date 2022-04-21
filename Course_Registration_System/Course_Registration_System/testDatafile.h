#pragma once

#include<iostream>
using namespace std;

void testDataFunction(Class& HCMUS){
    inputAllData(HCMUS);
    cout << HCMUS.staff_list.size() << endl;
    travel(it, HCMUS.staff_list){
        cout << (*it).id << " " << (*it).username << " " << (*it).password << endl;
    }
    cout << HCMUS.student_list.size() << endl;
    travel(it, HCMUS.student_list){
        cout << (*it).id << " " << (*it).username << " " << (*it).password << endl;
    }

    //outputStaffData(HCMUS);
    outputStudentData(HCMUS);
}
