#pragma once
#include"Node.h"
#include"User.h"
#include"SchoolYear.h"

struct Staff {
	string username;
	string password;
	User user_info;
};
bool operator == (const Staff& first, const Staff& second);

bool operator != (const Staff& first, const Staff& second);

void readCSV(Class& classname, string _inputfile);

void writeCSV(Node<Course>*& _course, const string& _outputfile);

