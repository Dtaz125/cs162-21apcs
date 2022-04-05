#pragma once
#include <iostream>
using namespace std;

const int baseX = 30;

///#include "Student.h"
struct Student{
    string name = "Vinh";
    string id = "21125030";
    string gender = "Male";
    string socialID = "192108211";
};

void changeName(Student &st){}
void changeID(Student &st){
    string new_ID;
    drawText(baseX, 3, "1. ID: "); cin >> new_ID;
    st.id = new_ID;
}
void changeBirthday(Student &st){}
void changeGender(Student &st){
    string new_gen;
    drawText(baseX, 6, "4. Gender: "); cin >> new_gen;
    st.gender = new_gen;
}
void changeSocialID(Student &st){
    string new_ID;
    drawText(baseX, 7, "5. Social ID: "); cin >> new_ID;
    st.socialID = new_ID;
}
void viewClass(Student st){}
void viewGPA(Student st){}
void viewListofCourse(Student st){}

void drawStudentProflie(Student &st)
{
    system("cls");
    int id;
    do{
        drawText(posCenter("Student Profile: "), 1, "Student Profile: ");
        drawText(baseX, 3, "1. ID: ");  cout << st.id;
        drawText(baseX, 4, "2. Full name: "); cout << st.name;
        drawText(baseX, 5, "3. Birthday: ");
        drawText(baseX, 6, "4. Gender: "); cout << st.gender;
        drawText(baseX, 7, "5. Social ID: "); cout << st.socialID;
        drawText(baseX, 8, "6. GPA: ");
        drawText(baseX, 9, "7. Class: ");
        drawText(baseX, 10, "8. List of course : ");
        drawText(baseX, 11, "9. Exit");
        drawText(posCenter("Press a number to change/view information: "), 12, "Press a number to change information: ");
        cin >> id;
        if (id == 1){
            changeID(st);
        }
        else if (id == 2){changeName(st);}
        else if (id == 3){changeBirthday(st);}
        else if (id == 4){changeGender(st);}
        else if (id == 5){changeSocialID(st);}
        else if (id == 6){viewGPA(st);}
        else if (id == 7){viewClass(st);}
        else if (id == 8){viewListofCourse(st);}
        system("cls");
    } while (id != 9);
    system("cls");
}
