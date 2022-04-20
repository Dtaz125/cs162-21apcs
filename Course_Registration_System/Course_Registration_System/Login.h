#pragma once
#include <iostream>
#include<fstream>
#include "Student.h"
#include "Staff.h"
#include "studentData.h"
#include "staffData.h"
using namespace std;

bool matched(Class& HCMUS, string username, string password, Student& st) {
    string accFile = "system/students/accounts.txt";
    ifstream acc(accFile);
    /// open File
    string id, us, pass;
    bool ok = false;
    ///
    while (!acc.eof()){
        /// search for accounts
        getline(acc, id, '\n');
        getline(acc, us, '\n');
        getline(acc, pass, '\n');
        /// get information
        if (username == us && password == pass) {
            getProfile(st, id);
            ok = true;
            drawText(baseX + 17, baseY+9, "Accepted!");
            _getch();
            break;
        }
    }
    acc.close();
    return ok;
}

bool matched(Class& HCMUS, string username, string password, Staff& st) {
    string id, us, pass;
    bool ok = false;
    ///
    int baseY = 11;
    travel(it, HCMUS.staff_list){
        /// search for accounts
        id = (*it).id;
        us = (*it).username;
        pass = (*it).password;
        /// get information
        if (username == us && password == pass) {
            st = (*it);
            ok = true;
            drawText(baseX + 5, baseY+5, blank);
            drawText(baseX + 17, baseY+5, "Accepted!");
            _getch();
            break;
        }
    }
    return ok;
}

/// Student/staff login(){}
void login(Class& HCMUS, auto& st) {
    bool first = true;
    int baseX = 10, baseY = 11;
    string username;
    string password;

    system("cls");
    cin.ignore();

    while (first || !matched(HCMUS, username, password, st)) {
        system("cls");
        if (!first) {
            drawText(posCenter("Invalid username or password!"), baseY + 5, "Invalid username or password!");
        }
        first = false;
        drawText(posCenter("LOGIN TO THE SYSTEM"), 9, "-----------------------");
        drawText(posCenter("LOGIN TO THE SYSTEM"), 10, "| LOGIN TO THE SYSTEM |");
        drawText(posCenter("LOGIN TO THE SYSTEM"), 11, "-----------------------");
        drawText(baseX + 24, baseY + 1, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        drawText(baseX+24, baseY + 2, "| Username:                       |");
        drawText(baseX+24, baseY + 3, "| Password:                       |");
        drawText(baseX + 24, baseY + 4, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

        drawText(baseX + 35, baseY + 2, " "); cin >> username;
        drawText(baseX + 35, baseY + 3, " "); cin >> password;
    }
    system("cls");
}
