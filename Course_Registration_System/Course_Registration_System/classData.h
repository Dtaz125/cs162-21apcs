#pragma once
#include <iostream>
#include"Class.h"
using namespace std;

void createClassesFolder(string Folder) {
    /*fstream g(Folder + "/classes.txt", ios::in | ios::app);
    int order = -1;
    while (g >> order) {
        if (order == se.order) return;
    }
    g.close();
    fstream f(Folder + "/names.txt", ios::app);
    f << se.order << endl;
    f.close();*/
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
