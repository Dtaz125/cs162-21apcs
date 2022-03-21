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
	Student() : Account() {}
	Student(string useracc, string pass, const User& info, string id, string NO) : Account(useracc, pass, info), studentid(id), no(NO) {}
	const string& getStudentID() { return studentid; }
	const string& getNO() { return no; }
	const Class& getClass() { return student_class; }
	float getGPA() { return gpa; }
	void setID(const string& id) { studentid = id; }
	void setNO(const string& NO) { no = NO; }
	void calculateGPA() {

	}
	void attend_course(const Course& course) {
		list_of_courses = new Node<Course>{ course, list_of_courses };
	}
	void empty_course() {
		Node<Course>* curr = nullptr;
		while (list_of_courses) {
			curr = list_of_courses;
			list_of_courses = list_of_courses->next;
			delete curr;
		}
	}
	friend bool operator == (const Student& student_1, const Student& student_2) {
		return student_1.studentid == student_2.studentid;
	}
	friend bool operator != (const Student& student_1, const Student& student_2) {
		return student_1.studentid != student_2.studentid;
	}
};

#endif // !STUDENT_H
