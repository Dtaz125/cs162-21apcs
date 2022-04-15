#include "MainGUI.h"
#include "Initialize.h"
#include "login.h"
#include "other.h"
using namespace std;
int main()
{
    InitializeConsole();

    bool isStudent = false;
    drawText(posCenter("COURSE REGISTRATION SYSTEM(Staff/Student): "), 10, "COURSE REGISTRATION SYSTEM(Staff/Student): ");
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
