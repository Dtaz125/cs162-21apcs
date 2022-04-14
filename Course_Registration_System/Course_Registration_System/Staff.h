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

//void readCSV(Node<SchoolYear>*& new_year, Class*& classname, const string& _inputfile);
void readCSV(Class*& classname, const string& _inputfile);

void writeCSV(Node<Course>*& _course, const string& _outputfile);

