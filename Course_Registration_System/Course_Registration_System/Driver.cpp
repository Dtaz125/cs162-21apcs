#include "MainGUI.h"
#include "Initialize.h"
#include "login.h"
#include "other.h"
#include "getData.h"
#include "testDatafile.h"
#include"CourseRegistrationData.h"
#include"calculateGPA.h"
using namespace std;
int main()
{
    Class HCMUS = {"HCMUS"};
    inputAllData(HCMUS);
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
   // Class tmp;
   // tmp.name = "21CTT1";
   // readCSV(tmp, "./class.csv");
   // outputClassData("system/schoolyears/2020-2021/classes", tmp);
   // Class tmp_1;
   // tmp_1.name = "21CTT1";
   // inputClassData("system/schoolyears/2020-2021/classes", tmp_1);
   //// //inputClassData("system/schoolyears/2020-2021/classes", tmp);
   //// //////inputClassData("system/schoolyears/2020-2021/classes", tmp);
   // cout << tmp_1.name << endl;
   // for (int i = 0; i < tmp_1.student_list.size(); i++) {
   //     cout << tmp_1.student_list[i]->data.user_info.firstname << endl << tmp_1.student_list[i]->data.user_info.lastname << endl << tmp_1.student_list[i]->data.user_info.gender << endl;
   // }
   // /*Course tmp;
   // readCSV_Scoreboard(tmp, "./Info_Course.csv");
   // for (int i = 0; i < tmp.student_score.size(); i++) {
   //     cout << tmp.student_score[i]->data.fullname << endl << tmp.student_score[i]->data.id << endl << tmp.student_score[i]->data.final_mark << endl;
   //}*/
   // /*Class tmp;
   // Student s;
   // inputStudentData(tmp);

   // for (int i = 0; i < tmp.student_list.size(); i++) {
   //     cout << tmp.student_list[i]->data.user_info.firstname << tmp.student_list[i]->data.user_info.lastname << endl;
   // }*/

    //Student s;
    //s.id = "21125054";
    //s.numcourse = 3;
    //s.init();
    //pair<string, string> p = make_pair("CS162", "Introduction to CS II"), k = make_pair("MTH252", "Calculus II"), m = make_pair("PH212", "General Physics II");
    //s.list_of_courses[0] = p; s.list_of_courses[1] = k; s.list_of_courses[2] = m;
    //for (int i = 0; i < s.numcourse; i++) {
    //    cout << s.list_of_courses[i].first << s.list_of_courses[i].second << endl;
    //}
    //float count = 0;
    ////cout << s.gpa << endl;
    //cout << calculateGPA(s, count)<<" "<<count;
    /*float gpa = calculateGPA(s);
    cout << gpa;*/
    /*Class tmp;
    Course c;
    inputCourseData(tmp);
    for (int i = 0; i < tmp.numcourse; i++) {
        cout << tmp.course_list[i].id << tmp.course_list[i].student_score[0]->data.fullname << endl;
    }*/
    return 0;
}
