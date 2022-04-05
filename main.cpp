#include "MainGUI.h"
#include "Initialize.h"
#include "login.h"
int main()
{
    InitializeConsole();
    Student st;
    ///st = login();
    login();
    drawMainGUI(st);
    return 0;
}
