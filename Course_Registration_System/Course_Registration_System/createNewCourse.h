#pragma once
#include"Course.h"
#include"Staff.h"
#include"Initialize.h"
#include"other.h"

void changeName(Course& c) {
    string new_name;
    drawText(baseX, baseY + 0, "1. Name: " + blank);
    drawText(baseX, baseY + 0, "1. Name: ");
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
    drawText(baseX, baseY + 2, "3. Teacher name: " + blank);
    drawText(baseX, baseY + 2, "3. Teacher name: ");
    cin.ignore();
    getline(cin, new_teacher);
    c.teacher_name = new_teacher;
}

void changeTeachingTime(Course& c) {
    string new_teacher;
    drawText(baseX, baseY + 3, "4. Teaching time: " + blank);
    drawText(baseX, baseY + 3, "4. Teaching time: ");
    cin.ignore();
    getline(cin, new_teacher);
    c.teaching_time = new_teacher;
}

void chanegMaxStudent(Course& c) {
    int new_number;
    drawText(baseX, baseY + 4, "5. Maximum Students: " + blank);
    drawText(baseX, baseY + 4, "5. Maximum Students: ");
    cin >> new_number;
    c.max_student = new_number;
}

void changeCredits(Course& c) {
    int new_number;
    drawText(baseX, baseY + 5, "6. Credits: " + blank);
    drawText(baseX, baseY + 5, "6. Credits: ");
    cin >> new_number;
    c.credits = new_number;
}
void createNewCourse(const SchoolYear& st) {
    int id;
    Course new_c;
    do {
        system("cls");
        drawText(posCenter("NEW COURSE"), 1, "NEW COURSE");
        drawText(baseX, baseY + 0, "1. Course Name: "); cout << new_c.name;
        drawText(baseX, baseY + 1, "2. Course ID: "); cout << new_c.id;
        drawText(baseX, baseY + 2, "3. Teacher: "); cout << new_c.teacher_name;
        drawText(baseX, baseY + 3, "4. Teaching Time: "); cout << new_c.teaching_time; 
        drawText(baseX, baseY + 4, "5. Maximum Students: "); cout << new_c.max_student;
        drawText(baseX, baseY + 5, "6. Credits: "); cout << new_c.credits;
        drawText(baseX, baseY + 6, "7. Create");
        drawText(baseX, baseY + 7, "8. Exit");
        //display course have created here
        drawText(posCenter("Press a number to change/view information: "), baseY + 8, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeName(new_c); }
        else if (id == 2) { changeID(new_c); }
        else if (id == 3) { changeTeacherName(new_c); }
        else if (id == 4) { changeTeachingTime(new_c); }
        else if (id == 5) { chanegMaxStudent(new_c); }
        else if (id == 6) { changeCredits(new_c); }
        else {
            //do something here
        }
        system("cls");
    } while (id != 8);
}