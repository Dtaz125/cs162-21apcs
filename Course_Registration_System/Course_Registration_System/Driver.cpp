#include "MainGUI.h"
#include "Initialize.h"
#include "login.h"
int main()
{
    InitializeConsole();
    bool isStudent = true; /// cin >> isStudent;
    if (isStudent) {
        Student st;
        ///st = login();
        login(st);
        drawMainGUI(st);
    }
    return 0;
}