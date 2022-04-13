#pragma once
#include"User.h"
#include"Linked_List.h"
#include"Course.h"
#include"Class.h"
#include<utility>
using std::pair;
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
