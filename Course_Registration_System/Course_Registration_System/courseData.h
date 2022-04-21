#pragma once
#include <iostream>
#include "direct.h"
using namespace std;

void outputCourseData(Class& HCMUS){
    string fileName = "system/courses.txt";
    ofstream f(fileName);
    for (int i = 0; i < HCMUS.course_list.size(); i++){
        f << HCMUS.course_list[i]->data;
    }
    f.close();
}

void inputCourseData(Class& HCMUS){
    HCMUS.course_list.empty_list();
    string fileName = "system/courses.txt";
    ifstream f(fileName);
    Course co;
    while (f >> co){
        HCMUS.course_list.add(co);
    }
    f.close();
}
