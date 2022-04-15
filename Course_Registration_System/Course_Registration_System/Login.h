#pragma once
#include <iostream>
#include<fstream>
#include "Student.h"
#include "Staff.h"
#include "getData.h"
using namespace std;

bool matched(string username, string password, Student& st) {
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
            drawText(baseX + 15, baseY, "Accepted!");
            _getch();
            break;
        }
    }
    acc.close();
    return ok;
}

bool matched(string username, string password, Staff& st) {
    string accFile = "system/staffs/accounts.txt";
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
            drawText(baseX + 15, baseY, "Accepted!");
            _getch();
            break;
        }
    }
    acc.close();
    return ok;
}

/// Student/staff login(){}
void login(auto& st) {
    bool first = true;
    int baseX = 10, baseY = 3;
    string username;
    string password;

    system("cls");
    cin.ignore();

    while (first || !matched(username, password, st)) {
        system("cls");
        if (!first) {
            drawText(posCenter("Invalid username or password!"), baseY + 5, "Invalid username or password!");
        }
        first = false;
        drawText(posCenter("LOGIN TO THE SYSTEM"), 1, "LOGIN TO THE SYSTEM");
        drawText(baseX, baseY + 1, "Username: ");
        drawText(baseX, baseY + 2, "Password: ");

        drawText(baseX + 9, baseY + 1, " "); cin >> username;
        drawText(baseX + 9, baseY + 2, " "); cin >> password;
    }
    system("cls");
}
