#pragma once
#include"User.h"
#include"Linked_List.h"
#include"Course.h"
#include"Class.h"
struct Course;
struct Class;
struct Student {
	string username;
	string password;
	User user_info = { "","",1,"", {0,0,0} };
	string studentid = "";
	string no = "";
	float gpa = 0;
	Class* student_class = nullptr;
	Linked_List<Course> list_of_courses;
};
bool operator == (const Student& student_1, const Student& student_2);

bool operator != (const Student& student_1, const Student& student_2);
//class Student : public Account {
//private:

//	void calculateGPA();
//public:
//	Student();
//	Student(string useracc, string pass, const User& info, string id, string NO);
//	Student(const Student& student);
//	const string& getStudentID();
//	const string& getNO();
//	Class* getClass();
//	float getGPA();
//	void setID(const string& id);
//	void setNO(const string& NO);
//	void setClass(Class* _class);
//	void attend_course(const Course& course);
//	void empty_course();
//	bool is_in_course(const Course& course);
//	const Iterator<Course> course_begin();
//	const Iterator<Course> course_end();
//	friend bool operator == (const Student& student_1, const Student& student_2);
//	friend bool operator != (const Student& student_1, const Student& student_2);
//	~Student();
//};

