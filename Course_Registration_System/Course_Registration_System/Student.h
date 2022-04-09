#ifndef STUDENT_H
#define STUDENT_H
#include"Linked_List.h"
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
	float gpa = 0;
	Class* student_class = nullptr;
	Linked_List<Course> list_of_courses;
	void calculateGPA();
public:
	Student();
	Student(string useracc, string pass, const User& info, string id, string NO);
	Student(const Student& student);
	const string& getStudentID();
	const string& getNO();
	Class* getClass();
	float getGPA();
	void setID(const string& id);
	void setNO(const string& NO);
	void setClass(Class* _class);
	void attend_course(const Course& course);
	void empty_course();
	bool is_in_course(const Course& course);
	const Iterator<Course> course_begin();
	const Iterator<Course> course_end();
	friend bool operator == (const Student& student_1, const Student& student_2);
	friend bool operator != (const Student& student_1, const Student& student_2);
	~Student();
};

#endif // !STUDENT_H
