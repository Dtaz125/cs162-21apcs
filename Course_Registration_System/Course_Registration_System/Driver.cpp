#include "MainGUI.h"
#include "Initialize.h"
#include "login.h"
#include "other.h"
#include "getData.h"
#include "testDatafile.h"
#include "CourseRegistrationData.h"
#define travel(it, var) for(auto it = var.begin(); it != var.end(); it++)
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
    return 0;
}
