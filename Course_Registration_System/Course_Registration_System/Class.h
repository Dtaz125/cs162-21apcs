#pragma once
#include"Iterator.h"
#include"Linked_List.h"
#include "Student.h"
#include "Staff.h"
#include<string>
struct Student;
struct Staff;
struct Class {
	std::string name;
	Linked_List<Student> student_list;
	Linked_List<Staff> staff_list;
	Class& operator = (Class& _class) { return _class; }
};
bool operator == (const Class& class_1, const Class& class_2);

bool operator != (const Class& class_1, const Class& class_2);

ofstream& operator << (ofstream& out_file, Class& _class);

ifstream& operator >> (ifstream& in_file, Class& _class);
