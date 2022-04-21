#pragma once
#include <iostream>
#include <direct.h>
using namespace std;

void createSchoolYear(SchoolYear& SY){
    string Folder = "system/schoolyears" + SY.name;
    string fileName = Folder + "/names.txt";
    mkdir(Folder.c_str());
    ofstream f(fileName, ios::app);
    f << SY.name << endl;
    f.close();
}
