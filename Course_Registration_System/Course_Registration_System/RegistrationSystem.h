#pragma once
#include"Linked_List.h"
#include"Staff.h"
#include"SchoolYear.h"
#include"Student.h"
struct Staff;
struct SchoolYear;
struct Student;
struct RegistrationSystem {
	string name;
	Linked_List<Student> students;
	Linked_List<Staff> academic_staffs;
	Linked_List<SchoolYear> schoolyears;
};
