#ifndef STUDENT_H
#define STUDENT_H
#include"Node.h"
#include"Account.h"
#include"Class.h"
#include"Course.h"
class Class;
class Account;
class Course;
class Student : public Account {
private:
	string studentid;
	string no;
	float gpa;
	Class* student_class = nullptr;
	Node<Course>* list_of_courses;
public:
	Student();
	Student(string useracc, string pass, const User& info, string id, string NO);
	Student(const Student& student);
	const string& getStudentID();
	const string& getNO();
	const Class* getClass();
	float getGPA();
	void setID(const string& id);
	void setNO(const string& NO);
	void setClass(Class* _class);
	void calculateGPA();
	void attend_course(const Course& course);
	void empty_course();
	friend bool operator == (const Student& student_1, const Student& student_2);
	friend bool operator != (const Student& student_1, const Student& student_2);
};

#endif // !STUDENT_H
