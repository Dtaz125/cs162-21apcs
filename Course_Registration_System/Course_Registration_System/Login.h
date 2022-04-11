#pragma once
#include <iostream>
#include<fstream>
#include "Student.h"
#include "Staff.h"

using namespace std;

const string nameFile = "data.txt";

bool matched(string username, string password, Student& st) {
    ifstream inp(nameFile);
    bool ok; cin >> ok;
    return ok;
}

bool matched(string username, string password, Staff& st) {
    ifstream inp(nameFile);
    bool ok; cin >> ok;
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
            drawText(posCenter("Invalid username or password"), baseY + 5, "Invalid username or password");
        }
        first = false;
        drawText(posCenter("Log in to the system: "), 1, "Log in to the system:");
        drawText(baseX, baseY + 1, "Username: ");
        drawText(baseX, baseY + 2, "Password: ");

        drawText(baseX + 9, baseY + 1, " "); cin >> username;
        drawText(baseX + 9, baseY + 2, " "); cin >> password;
    }
    system("cls");
}
