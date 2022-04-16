#pragma once
#include<string>
#include"Date.h"
#include"Initialize.h"
struct CourseRegistration {
	std::string name = "";
	Date start_date = { 0,0,0 };
	Date end_date = { 0,0,0 };
};

void changeName(CourseRegistration& new_c, int baseX, int baseY, string text) {
    string new_name;
    drawText(baseX, baseY, text + blank);
    drawText(baseX, baseY, text);
    cin.ignore();
    getline(cin, new_name);
    new_c.name = new_name;
}

void changeStartDate(CourseRegistration& new_c, int baseX, int baseY, string text) {
    string new_date;
    drawText(baseX, baseY, text + blank);
    drawText(baseX, baseY, text);
    cin.ignore();
    getline(cin, new_date);
    validDate(new_date, new_c.start_date);
}

void changeEndDate(CourseRegistration& new_c, int baseX, int baseY, string text) {
    string new_date;
    drawText(baseX, baseY, text + blank);
    drawText(baseX, baseY, text);
    cin.ignore();
    getline(cin, new_date);
    validDate(new_date, new_c.end_date);
}