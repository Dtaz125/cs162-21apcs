#pragma once
#include"Linked_List.h"
#include"Staff.h"
#include"SchoolYear.h"
#include"Student.h"
class Staff;
class SchoolYear;
class Student;
class RegistrationSystem {
private:
	string name;
	Linked_List<Student> students;
	Linked_List<Staff> academic_staffs;
	Linked_List<SchoolYear> schoolyears;
public:
	RegistrationSystem(const string& _name);
	int count_staff();
	int count_student();
	const string& getName();
	Node<Student>* access_student(const Student& _student);
	Node<Staff>* access_staff(const Staff& _staff);
	Node<SchoolYear>* access_year(const SchoolYear& _year);
	bool add(const Staff& new_staff);
	void add(const Linked_List<Staff>& staff_list);
	bool add(const Student& new_student);
	void add(const Linked_List<Student>& student_list);
	bool add(const SchoolYear& new_year);
	void add(const Linked_List<SchoolYear>& year_list);
	void remove(const Staff& new_staff);
	void remove(const Linked_List<Staff>& staff_list);
	void remove(const Student& new_student);
	void remove(const Linked_List<Student>& student_list);
	void remove(const SchoolYear& new_year);
	void remove(const Linked_List<SchoolYear>& year_list);
	const Iterator<Student> student_begin();
	const Iterator<Student> student_end();
	const Iterator<Staff> staff_begin();
	const Iterator<Staff> staff_end();
	const Iterator<SchoolYear> year_begin();
	const Iterator<SchoolYear> year_end();
	~RegistrationSystem();
};