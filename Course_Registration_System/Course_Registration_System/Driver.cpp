#include "MainGUI.h"
#include "Initialize.h"
#include "login.h"
#include "other.h"

using namespace std;
int main()
{
     InitializeConsole();

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
    return 0; 
}
