#pragma once
#include <iostream>
#include"other.h"
#include<sstream>
using namespace std;

const int baseX = 30;
const string blank = "                                                     ";
#include "Student.h"
#include"Initialize.h"
string getGender(Student st) {
    if (st.getInfo().gender == 0) return "Male";
    return "Female";
}

void changeID(Student& st) {
    string new_ID;
    drawText(baseX, 3, "1. ID: " + blank);
    drawText(baseX, 3, "1. ID: ");
    cin >> new_ID;
    st.setID(new_ID);
}

void changeName(Student& st) {
    string new_name;
    drawText(baseX, 4, "2. Full name: " + blank);
    drawText(baseX, 4, "2. Full name: ");
    cin.ignore();
    getline(cin, new_name);
    User tmp = st.getInfo();
    int pos = -1;
    for (int i = new_name.size() - 1; i >= 0; i--) {
        if (new_name[i] == ' ') {
            pos = i;
            break;
        }
    }
    tmp.firstname = "";
    tmp.lastname = "";
    for (int i = 0; i < pos; i++)
        tmp.firstname += new_name[i];
    for (int i = pos + 1; i < new_name.size(); i++)
        tmp.lastname += new_name[i];

    st.setInfo(tmp);
}

void changeBirthday(Student& st) {
    drawText(baseX, 5, "3. Birthday: " + blank);
    drawText(baseX, 5, "3. Birthday: ");
    cin.ignore();
    User info = st.getInfo();
    string birth;
    getline(cin, birth);
    Date tmp;
    if (!validDate(birth, tmp)) return;
    info.birth = tmp;
    st.setInfo(info);
}
void changeGender(Student& st) {
    string new_gen;
    drawText(baseX, 6, "4. Gender(Male/Female): " + blank);
    drawText(baseX, 6, "4. Gender(Male/Female): ");
    cin >> new_gen;
    User tmp = st.getInfo();
    if (new_gen == "Male") tmp.gender = 0;
    else tmp.gender = 1;
    st.setInfo(tmp);
}
void changeSocialID(Student& st) {
    string new_ID;
    drawText(baseX, 7, "5. Social ID: " + blank);
    drawText(baseX, 7, "5. Social ID: ");
    cin >> new_ID;
    User tmp = st.getInfo();
    tmp.social_id = new_ID;
    st.setInfo(tmp);
}
void viewClass(Student st) {
    system("cls");
    Class* new_class = st.getClass();
    drawText(baseX, 7, "Classname: " + new_class->getName()); cout << endl;
    drawText(baseX, 8, "Student list: "); cout << endl;
    int i = 9, index = 1;
    for (Iterator<Student> iter = new_class->student_begin(); iter != new_class->student_end(); iter++) {
        Student k = *iter;
        drawText(baseX + 1, i++, to_string(index) + ". " + k.getInfo().firstname + " " + k.getInfo().lastname); cout << endl;
        index++;
    }
}
void viewGPA(Student st) {

}
void viewListofCourse(Student st) {
    system("cls");
    int i = 7, index = 1;
    for (Iterator<Course> iter = st.course_begin(); iter != st.course_end(); iter++) {
        Course k = *iter;
        drawText(baseX, i++, to_string(index) + ". " + k.getCourseName() + " | Teacher: " + k.getTeacherName()); cout << endl;
        index++;
    }
    
}

void drawStudentProfile(Student& st) {
    system("cls");
    int id;
    do {
        drawText(posCenter("Student Profile: "), 1, "Student Profile: ");
        drawText(baseX, 3, "1. ID: ");  cout << st.getStudentID();
        drawText(baseX, 4, "2. Full name: "); cout << st.getInfo().firstname << " " << st.getInfo().lastname;
        drawText(baseX, 5, "3. Birthday: "); cout << st.getInfo().birth.day << "/" << st.getInfo().birth.month << "/" << st.getInfo().birth.year;
        drawText(baseX, 6, "4. Gender(Male/Female): "); cout << getGender(st);
        drawText(baseX, 7, "5. Social ID: "); cout << st.getInfo().social_id;
        drawText(baseX, 8, "6. GPA: "); cout << st.getGPA();
        drawText(baseX, 9, "7. Class: "); 
        drawText(baseX, 10, "8. List of course : "); 
        drawText(baseX, 11, "9. Exit");
        drawText(posCenter("Press a number to change/view information: "), 12, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) {
            changeID(st);
        }
        else if (id == 2) { changeName(st); }
        else if (id == 3) { changeBirthday(st); }
        else if (id == 4) { changeGender(st); }
        else if (id == 5) { changeSocialID(st); }
        else if (id == 6) { viewGPA(st); }
        else if (id == 7) { viewClass(st); }
        else if (id == 8) { viewListofCourse(st); }
        system("cls");
    } while (id != 9);
    system("cls");
}