#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include"Linked_List.h"
#include"Account.h"
#include"Course.h"
#include"Class.h"

class Student : public Account {
private:
	string studentid;
	string no;
	float gpa;
	Class student_class;
	Linked_List<Course> list_of_courses;
public:
	Student() : Account() {}
	Student(string useracc, string pass, const User& info, string id, string NO) : Account(useracc, pass, info), studentid(id), no(NO) {}
	const string& getStudentID() { return studentid; }
	const string& getNO() { return no; }
	float getGPA() { return gpa; }
	void setID(const string& id) { studentid = id; }
	void setNO(const string& NO) { no = NO; }
	friend bool operator == (const Student& student_1, const Student& student_2) {
		return student_1.studentid == student_2.studentid;
	}
	friend bool operator != (const Student& student_1, const Student& student_2) {
		return student_1.studentid != student_2.studentid;
	}
};

#endif // !STUDENT_H
