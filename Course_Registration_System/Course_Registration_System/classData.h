
#pragma once
#include <iostream>
#include"Class.h"
using namespace std;

void createClassesFolder(string Folder) {
    _mkdir((Folder + "/classes").c_str());
}

void inputClassData(string classFolder, Class& se) {
    ofstream tmp(classFolder + "/" + se.name + ".txt", ios::app);
    tmp.close();
    Class temp;
    ifstream f(classFolder + "/" + se.name + ".txt");
    if (!f.eof()) f >> temp;
    se = temp;
    f.close();
}

void outputClassData(string classFolder, Class& se) {
    ofstream tmp(classFolder + "/" + se.name + ".txt", ios::out);
    tmp << se;
    tmp.close();
}
