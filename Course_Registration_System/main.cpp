#include "MainGUI.h"
#include "Initialize.h"
#include "login.h"
#include "other.h"
int main()
{
    InitializeConsole();
    bool isStudent = false; /// cin >> isStudent;
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
