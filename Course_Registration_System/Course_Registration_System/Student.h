#pragma once
#include"User.h"
#include"Linked_List.h"
#include<utility>
#include<fstream>
using std::pair;
using std::ofstream;
using std::ifstream;
struct Course;
struct Class;
struct Student {
	string username;
	string password;
	User user_info = { "","",1,"", {0,0,0} };
	string studentid = "";
	string no = "";
	float gpa = 0;
	string student_class = ""; //name of the class
	Linked_List<pair<string, string>> list_of_courses; //CourseID - Full name
};
bool operator == (const Student& student_1, const Student& student_2);

bool operator != (const Student& student_1, const Student& student_2);

ofstream& operator << (ofstream & out_file, Student & student);

ifstream& operator >> (ifstream& in_file, Student& student);