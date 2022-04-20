#include "MainGUI.h"
#include "Initialize.h"
#include "login.h"
#include "other.h"
#include "getData.h"
#include "testDatafile.h"
#define travel(it, var) for(auto it = var.begin(); it != var.end(); it++)
using namespace std;
int main()
{
    Class HCMUS = {"HCMUS"};
    testDataFunction(HCMUS);
    return 0;
    system("Color 9F");
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
