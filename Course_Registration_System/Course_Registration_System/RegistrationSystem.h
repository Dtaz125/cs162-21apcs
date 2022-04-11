#pragma once
#include"Linked_List.h"
#include"Staff.h"
#include"SchoolYear.h"
#include"Student.h"
class Staff;
class SchoolYear;
class Student;
struct RegistrationSystem {
	string name;
	Linked_List<Student> students;
	Linked_List<Staff> academic_staffs;
	Linked_List<SchoolYear> schoolyears;
};
