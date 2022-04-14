//#include "MainGUI.h"
//#include "Initialize.h"
//#include "login.h"
//#include "other.h"
#include<iostream>
#include"Staff.h"
#include"Course.h"
using namespace std;
int main()
{
     /*InitializeConsole();

    bool isStudent = false;
    drawText(posCenter("Course Registration System(Staff/Student): "), 10, "Course Registration System(Staff/Student): ");
    cin >> isStudent;
    Student stu;
    Staff sta;
    if (isStudent) {
        login(stu);
        drawMainGUI(stu, 1);
    }
    else {
        login(sta);
        drawMainGUI(sta, 0);
    }
    return 0; */

    Course k;
    readCSV_Scoreboard(k, "test_course.csv");
    cout << k.student_score.size();

    for (int i = 0; i < k.student_score.size(); i++) {
        Score p = k.student_score[i]->data;
        cout << p.no << " " << p.id << " " << p.fullname << " " << " " << p.total_mark << ' ' << p.final_mark << " " << p.midterm_mark << " ";
        for (int i = 0; i < p.number_of_other_score; i++) {
            cout << p.other_score[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
