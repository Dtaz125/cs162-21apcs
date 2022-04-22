#pragma once
#include <iostream>
using namespace std;

void createSemesterFolder(string Folder, Semester& se){
    fstream g(Folder + "/names.txt", ios::in|ios::app);
    int order = -1;
    while (g >> order){
        if (order == se.order) return;
    }
    g.close();
    fstream f(Folder + "/names.txt", ios::app);
    f << se.order << endl;
    f.close();
    mkdir((Folder + "/semester" + to_string(se.order)).c_str());
}

void inputSemesterData(string semesterFolder, Semester &se){
    ofstream tmp(semesterFolder + "/names.txt", ios::app);
    tmp.close();
    Semester temp;
    temp.order = se.order;
    ifstream f(semesterFolder + "/names.txt");
    if (!f.eof()) f >> temp;
    se = temp;
    f.close();
}

void outputSemesterData(string semesterFolder, Semester& se){
    ofstream f(semesterFolder + "/names.txt", ios::out);
    f << se;
    f.close();
}
