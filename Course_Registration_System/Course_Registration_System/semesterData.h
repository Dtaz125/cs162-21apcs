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
