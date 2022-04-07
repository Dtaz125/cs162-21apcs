#pragma once
#include"Linked_List.h"
#include"Semester.h"
#include<string>
class Semester;
class SchoolYear {
private:
	string name;
	Linked_List<Semester> list_of_semesters;
public:
	SchoolYear(const string& _name);
	const string& getName();
	bool contains(const Semester& _semester);
	Node<Semester>* access_semester(const Semester& _semester);
	Node<Semester>* access_semester(int order);
	bool add(const Semester& _semester);
	void add(const Linked_List<Semester>& list);
	bool remove(const Semester& _semester);
	void remove(const Linked_List<Semester>& list);
	friend bool operator == (const SchoolYear& first, const SchoolYear& second);
	friend bool operator != (const SchoolYear& first, const SchoolYear& second);
	const Iterator<Semester> semester_begin();
	const Iterator<Semester> semester_end();
	~SchoolYear();
};


