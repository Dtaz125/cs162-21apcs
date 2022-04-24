#pragma once

#include"Node.h"
#include"User.h"
#include"SchoolYear.h"

struct Staff {
	string id;
	string username;
	string password;
	User user_info;
};
bool operator == (const Staff& first, const Staff& second);

bool operator != (const Staff& first, const Staff& second);

void readCSV(Class& classname, string _inputfile);

void writeCSV(Course& _course, const string& _outputfile);

void readCSV_Scoreboard(Course& _course, const string& _inputfile);

void writeCSV_Scoreboard(Course& _course, string _outputfile);