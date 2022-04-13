#pragma once
#include"Node.h"
#include"User.h"
#include"SchoolYear.h"

struct Staff {
	string username;
	string password;
	User user_info;
};
bool operator == (const Staff& first, const Staff& second);

bool operator != (const Staff& first, const Staff& second);

void readCSV(Node<SchoolYear>*& new_year, Class*& classname, const string& _inputfile);

void writeCSV(Course*& _course, const string& _outputfile);

//class Staff {
//private:

//public:
//	Staff();
//	Staff(string useracc, string pass, const User& info);
//	Staff(const Staff& staff);
//	const string& getUsername();
//	const string& getPassword();
//	const User& getInfo();
//	void setUsername(string useracc);
//	void setPassword(string pass);
//	void setInfo(const User& info);
//	void readCSV(Node<SchoolYear>*& new_year, Class*& classname, const string& _inputfile);
//	Semester& create_semester(int order, const Date& start, const Date& end);
//	Course& create_course(string __id, string __name, string __teacher_name, int credits);
//	bool add_semester_to_schoolyear(const Semester& new_semester, Node<SchoolYear>*& schoolyear);
//	bool add_course_to_semester(const Course& new_course, Node<Semester>*& semester);
//	bool remove_course(const Course& course, Node<Semester>*& semester);
//	friend bool operator == (const Staff& first, const Staff& second);
//	friend bool operator != (const Staff& first, const Staff& second);
//};
