#pragma once
#include <iostream>
#include <direct.h>
using namespace std;

void createSchoolYear(SchoolYear& SY){
    string Folder = "system/schoolyears/" + SY.name;
    string fileName = "system/schoolyears/names.txt";
    fstream g(fileName, ios::in);
    string name;
    while (g >> name){
        if (name == SY.name) return;
    }
    g.close();
    _mkdir(Folder.c_str());
    fstream f(fileName, ios::app);
    f << SY.name << endl;
    f.close();
}
