#pragma once
#include"Course.h"
#include"Staff.h"
#include"Initialize.h"
#include"other.h"
#include<algorithm>
#include<cctype>
#include<locale>
#include<string>
#include<iostream>
using namespace std;
string toUpperCase(string& str) {                          //utility to change to uppercase
    transform(str.begin(), str.end(), str.begin(), ::toupper);

    return str;
}

string converting_time(string input) {
    string sub = input.substr(1, 1);                            //S1 -> 1
    int date = stoi(sub);                                       //convert string "1" to int
    string sub2;

    switch (date) {
    case 1: {
        sub2 = "7h30";
        break;
    }
    case 2: {
        sub2 = "9h30";
        break;
    }
    case 3: {
        sub2 = "13h30";
        break;
    }
    case 4: {
        sub2 = "15h30";
        break;
    }
    }

    return sub2;
}

static inline void ltrim(std::string& s) {                                          //left trim
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
        }));
}

static inline void rtrim(std::string& s) {                                          //right trim
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
        }).base(), s.end());
}

static inline std::string trim_copy(std::string s) {                                //use this function to trim strings
    ltrim(s);
    rtrim(s);

    return s;
}

string convert_teachingtime(string input) {                     //TueS1 - ThuS2
    string trimmed = trim_copy(input);                            //trimming string
    string sub1 = trimmed.substr(0, 3);                           //Tue
    string sub2 = trimmed.substr(3, 2);                           //S1
    string sub3 = trimmed.substr(6, 3);                           //Thu
    string sub4 = trimmed.substr(9, 2);                           //S2
    string sub5 = toUpperCase(sub1) + " - " + converting_time(sub2) + " / " + toUpperCase(sub3) + " - " + converting_time(sub4);

    return sub5;                                                //TUE - 7:30 / THU - 9:30
}

void changeName(Course& c) {
    string new_name;
    drawText(baseX, baseY - 1, "1. Name: " + blank);
    drawText(baseX, baseY - 1, "1. Name: ");
    cin.ignore();
    getline(cin, new_name);
    c.name = new_name;
}

void changeID(Course& c) {
    string new_id;
    drawText(baseX, baseY + 1, "2. ID: " + blank);
    drawText(baseX, baseY + 1, "2. ID: ");
    cin.ignore();
    getline(cin, new_id);
    c.id = new_id;
}

void changeTeacherName(Course& c) {
    string new_teacher;
    drawText(baseX, baseY + 3, "3. Teacher Name: " + blank);
    drawText(baseX, baseY + 3, "3. Teacher Name: ");
    cin.ignore();
    getline(cin, new_teacher);
    c.teacher_name = new_teacher;
}

void changeTeachingTime(Course& c) {
    string new_teacher;
    drawText(baseX, baseY + 5, "4. Teaching Time: " + blank);
    drawText(baseX, baseY + 5, "4. Teaching Time: ");
    cin.ignore();
    getline(cin, new_teacher);
    c.teaching_time = convert_teachingtime(new_teacher);
}

void chanegMaxStudent(Course& c) {
    int new_number;
    drawText(baseX, baseY + 7, "5. Maximum Students: " + blank);
    drawText(baseX, baseY + 7, "5. Maximum Students: ");
    cin >> new_number;
    c.max_student = new_number;
}

void changeCredits(Course& c) {
    int new_number;
    drawText(baseX, baseY + 9, "6. Credits: " + blank);
    drawText(baseX, baseY + 9, "6. Credits: ");
    cin >> new_number;
    c.credits = new_number;
}
void createNewCourse(Class& HCMUS, Semester& st) {
    int id, baseY=3;
    Course new_c;
    new_c.student_score.empty_list();
    do {
        system("cls");
        drawText(posCenter("NEW COURSE"), baseY, "--------------");
        drawText(posCenter("NEW COURSE"), baseY + 1, "| NEW COURSE |");
        drawText(posCenter("NEW COURSE"), baseY + 2, "--------------");
        drawText(baseX, baseY + 3, "1. Course Name: "); cout << new_c.name;
        drawText(baseX, baseY + 5, "2. Course ID: "); cout << new_c.id;
        drawText(baseX, baseY + 7, "3. Teacher: "); cout << new_c.teacher_name;
        drawText(baseX, baseY + 9, "4. Teaching Time: "); cout << new_c.teaching_time;
        drawText(baseX, baseY + 11, "5. Maximum Students: "); cout << new_c.max_student;
        drawText(baseX, baseY + 13, "6. Credits: "); cout << new_c.credits;
        drawText(baseX, baseY + 15, "7. Save and create");
        drawText(baseX, baseY + 17, "8. Exit");
        //display course have created here
        drawText(posCenter("Press a number to change/view information: "), baseY + 19, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeName(new_c); }
        else if (id == 2) { changeID(new_c); }
        else if (id == 3) { changeTeacherName(new_c); }
        else if (id == 4) { changeTeachingTime(new_c); }
        else if (id == 5) { chanegMaxStudent(new_c); }
        else if (id == 6) { changeCredits(new_c); }
        else {
           st.list_of_courses.add({new_c.id, new_c.name});
           HCMUS.course_list[HCMUS.numcourse++] = new_c;
           outputCourseData(HCMUS);
        }
        system("cls");
    } while (id != 8 && id != 7);
}

