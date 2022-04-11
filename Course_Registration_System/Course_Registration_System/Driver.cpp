#include "MainGUI.h"
#include "Initialize.h"
#include "login.h"
#include "other.h"
int main()
{
    /*InitializeConsole();
    bool isStudent;  cin >> isStudent;
    Student stu;
    Staff sta;
    if (isStudent) {
        login(stu);
        drawMainGUI(stu, 1);
    }
    else {
        login(sta);
        drawMainGUI(sta, 0);
    }*/

    Student k;
    Course course("Introduction to CS", "CS162", "DBT");
    
    k.setID("21125054");
    course.publishCourse();
    course.add_student(k);
    k.attend_course(course);
    pair<string, int> scorelist;
    scorelist = make_pair("21125054", 10); 
    course.add_score(scorelist);

    cout << "Score:";
    for (Iterator<pair<string, int>> iter = course.score_begin(); iter != course.score_end(); iter++) {
        pair<string, int> i = *iter;
        if (i.first == k.getStudentID()) {
            cout << i.second;
            break;
        }
    }
   
    cout << "Before published course: \tGPA: " << k.getGPA()<<endl;
    cout << "After published course: \tGPA: ";
  

    return 0;
}