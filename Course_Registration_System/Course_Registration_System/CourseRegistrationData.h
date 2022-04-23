#pragma once
#include <iostream>
using namespace std;

void outputRegisData(CourseRegistration reg){
    string fileName = "system/schoolyears/" + reg.syear + "/semester" + reg.semester
    + "/courseRegistration.txt";
    ofstream f(fileName);
    f << reg.active << endl;
    f << reg.start_date.day << " " << reg.start_date.month << " " << reg.start_date.year << endl;
    f << reg.end_date.day << " " << reg.end_date.month << " " << reg.end_date.year << endl;
    f << reg.numcourse << endl;
    for (int i = 0; i < reg.numcourse; i++){
        f << reg.courseID[i] << endl << reg.maxstudent[i] << " " << reg.curstudent[i] << endl;
        for (int j = 0; j < reg.curstudent[i]; j++){
            f << reg.students[i][j].first << endl << reg.students[i][j].second << endl;
        }
    }
    f.close();
}

void inputRegisData(CourseRegistration& reg, string syear, string semester){
    mkdir(("system/schoolyears/" + syear).c_str());
    mkdir(("system/schoolyears/" + syear + "/semester" + semester).c_str());
    string fileName = "system/schoolyears/" + syear + "/semester" + semester
    + "/courseRegistration.txt";
    ofstream g(fileName, ios::app);
    g.close();
    ifstream f(fileName);
    reg.clear();
    if (!f.is_open()) return;
    if (!f.eof()){
    reg.syear = syear;
    reg.semester = semester;
    f >> reg.active;
    f >> reg.start_date.day >> reg.start_date.month >> reg.start_date.year;
    f >> reg.end_date.day >> reg.end_date.month >> reg.end_date.year;
    f >> reg.numcourse; f.ignore();
    reg.init();
    for (int i = 0; i < reg.numcourse; i++){
        getline(f, reg.courseID[i]);
        f >> reg.maxstudent[i] >> reg.curstudent[i];
        f.ignore();
        reg.students[i] = new pair<string, string> [reg.curstudent[i]];
        for (int j = 0; j < reg.curstudent[i]; j++){
            getline(f, reg.students[i][j].first);
            getline(f, reg.students[i][j].second);
        }
    }
    }
    f.close();
}
