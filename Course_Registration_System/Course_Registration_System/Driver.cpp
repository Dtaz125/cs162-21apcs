#include "MainGUI.h"
#include "Initialize.h"
#include "login.h"
#include "other.h"
#include "getData.h"
#include "testDatafile.h"
#include"CourseRegistrationData.h"
#define travel(it, var) for(auto it = var.begin(); it != var.end(); it++)
using namespace std;

int main()
{
    Class HCMUS = {"HCMUS"};
    inputAllData(HCMUS);
    outputStudentData(HCMUS);
    return 0;
    system("Color 9F");
    InitializeConsole();
    bool isStudent = false;
    drawText(posCenter("COURSE REGISTRATION SYSTEM(Staff/Student)[0/1]: "), 10, "COURSE REGISTRATION SYSTEM(Staff/Student)[0/1]: ");
    cin >> isStudent;
    Student stu;
    Staff sta;
    if (isStudent) {
        login(HCMUS, stu);
        drawMainGUI(HCMUS, stu, 1);
    }
    else {
        login(HCMUS, sta);
        drawMainGUI(HCMUS, sta, 0);
    }
    //Class tmp;
    //tmp.name = "21CTT1";
    ////readCSV(tmp, "./test_csv.csv");
    //inputClassData("system/schoolyears/2020-2021/classes", tmp);
    //for (int i = 0; i < tmp.student_list.size(); i++) {
    //    cout << tmp.student_list[i]->data.user_info.firstname << endl << tmp.student_list[i]->data.user_info.lastname << endl << tmp.student_list[i]->data.user_info.gender << endl;
    //}
    /*Course tmp;
    readCSV_Scoreboard(tmp, "./Info_Course.csv");
    for (int i = 0; i < tmp.student_score.size(); i++) {
        cout << tmp.student_score[i]->data.fullname << endl << tmp.student_score[i]->data.id << endl << tmp.student_score[i]->data.final_mark << endl;
   }*/
    return 0;
}
