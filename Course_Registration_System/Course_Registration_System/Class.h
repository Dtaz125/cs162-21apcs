#pragma once
#include"Iterator.h"
#include"Linked_List.h"
#include "Student.h"
#include "Staff.h"
#include<string>
#include <vector>
struct Student;
struct Staff;
struct Score;
struct Course;
struct Class {
	std::string name;
	Linked_List<Student> student_list;
	Linked_List<Staff> staff_list;
	Course* course_list;
	int numcourse = 0;
	Class& operator = (Class& _class) { return _class; }
};
bool operator == (const Class& class_1, const Class& class_2);

bool operator != (const Class& class_1, const Class& class_2);

ofstream& operator << (ofstream& out_file, Class& _class);

ifstream& operator >> (ifstream& in_file, Class& _class);