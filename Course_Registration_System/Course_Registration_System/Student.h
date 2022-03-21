#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include"Account.h"
#include"Course.h"
#include"Class.h"
#include"Node.h"
class Student : public Account {
private:
	string studentid;
	string no;
	float gpa;
	Class student_class;
	Node<Course>* list_of_courses;
public:
	Student();
	Student(string useracc, string pass, const User& info, string id, string NO);
	const string& getStudentID();
	const string& getNO();
	const Class& getClass();
	float getGPA();
	void setID(const string& id);
	void setNO(const string& NO);
	void calculateGPA();
	void attend_course(const Course& course);
	void empty_course();
	friend bool operator == (const Student& student_1, const Student& student_2);
	friend bool operator != (const Student& student_1, const Student& student_2);
};

#endif // !STUDENT_H
