#pragma once
#include"Linked_List.h"
#include"Semester.h"
#include<string>
struct Semester;
struct SchoolYear {
	string name = "";
	Linked_List<Semester> list_of_semesters;
};

ofstream& operator << (ofstream& out_file, SchoolYear& schooyear);

ifstream& operator >> (ifstream& in_file, SchoolYear& schooyear);

bool operator == (const SchoolYear& first, const SchoolYear& second);

bool operator != (const SchoolYear& first, const SchoolYear& second);




