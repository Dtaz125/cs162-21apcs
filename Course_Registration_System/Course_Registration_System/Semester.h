#pragma once
#include"Linked_List.h"
#include"Class.h"
#include"Course.h"
#include"Date.h"
#include<fstream>
#include<utility>
using namespace std;
struct Class;
struct Course;
struct Semester {
	Linked_List<string> list_of_classes; //Just the name of the classes
	Linked_List<pair<string, string>> list_of_courses; //Co	urseID - Course name
	int order = 0;
	Date start_date = { 0,0,0 };
	Date end_date = { 0,0,0 };

	Semester& operator = (Semester& sem) { return sem; }
};

bool operator == (const Semester& first, const Semester& second);

bool operator != (const Semester& first, const Semester& second);

ofstream& operator << (ofstream& out_file, Semester& semester);

ifstream& operator >> (ifstream& in_file, Semester& semester);

