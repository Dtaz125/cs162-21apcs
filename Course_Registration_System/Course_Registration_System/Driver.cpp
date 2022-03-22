#include<iostream>
#include"Student.h"
#include"Semester.h"
#include"Class.h"
using namespace std;
int main() {
	Student stu;
	Class CTT1("21CTT1", 50);
	stu.setID("21125054");
	stu.setClass(&CTT1);
	cout << stu.getStudentID();
	return 0;
}