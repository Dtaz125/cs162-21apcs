#pragma once
#include<string>
#include"Date.h"
#include"Initialize.h"
using namespace std;
struct CourseRegistration {
    bool active = true;;
    string syear = "";
    string semester = "0";
    Date start_date = { 0,0,0 };
    Date end_date = { 0,0,0 };
    int numcourse = 0;
    string* courseID;
    int* maxstudent, * curstudent;
    pair<string, string>** students;
    void clear() {
        active = true;
        start_date = end_date = { 0, 0, 0 };
        numcourse = 0;
    }
    void init() {
        courseID = new string[numcourse + 10];
        maxstudent = new int[numcourse + 10];
        curstudent = new int[numcourse + 10];
        students = new pair <string, string> *[numcourse + 10];
        //for (int i = 0; i < numcourse + 8; i++)
          //  students[i] = new pair<string, string> [curstudent[i] + 8];
    }
    void addCourse(string id, int maxst) {
        maxstudent[numcourse] = maxst;
        curstudent[numcourse] = 0;
        courseID[numcourse] = id;
        numcourse++;
    }

    bool addStudent(int no, string id, string fullname){
        if (curstudent[no] == maxstudent[no]) return false;
        int n = curstudent[no]++;
        students[no][n] = {id, fullname};
        return true;
    }
};

void addCourse(CourseRegistration& new_c, int baseX, int baseY, string text, string text2) {
    string new_name;
    int maxST;
    drawText(baseX, baseY, text + blank);
    drawText(baseX, baseY, text);
    cin.ignore();
    getline(cin, new_name);
    drawText(baseX, baseY + 2, text2 + blank);
    drawText(baseX, baseY + 2, text2);
    cin >> maxST;
    new_c.addCourse(new_name, maxST);
}

void changeSchoolyear(CourseRegistration& new_c, int baseX, int baseY, string text) {
    string new_name;
    drawText(baseX, baseY, text + blank);
    drawText(baseX, baseY, text);
    cin.ignore();
    getline(cin, new_name);
    new_c.syear = new_name;
}

void changeSemester(CourseRegistration& new_c, int baseX, int baseY, string text) {
    string new_name;
    drawText(baseX, baseY, text + blank);
    drawText(baseX, baseY, text);
    cin.ignore();
    getline(cin, new_name);
    new_c.semester = new_name;
}

void changeStartDate(CourseRegistration& new_c, int baseX, int baseY, string text) {
    string new_date;
    drawText(baseX, baseY, text + blank);
    drawText(baseX, baseY, text);
    cin.ignore();
    getline(cin, new_date);
    validDate(new_date, new_c.start_date);
}

void changeEndDate(CourseRegistration& new_c, int baseX, int baseY, string text) {
    string new_date;
    drawText(baseX, baseY, text + blank);
    drawText(baseX, baseY, text);
    cin.ignore();
    getline(cin, new_date);
    validDate(new_date, new_c.end_date);
}
