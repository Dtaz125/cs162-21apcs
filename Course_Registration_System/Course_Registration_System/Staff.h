
#ifndef STAFF_H
#define STAFF_H
#include"Account.h"
#include"SchoolYear.h"
class SchoolYear;
class Staff {
private:
	string username;
	string password;
	User user_info;
public:
	Staff();
	Staff(string useracc, string pass, const User& info);
	Staff(const Staff& staff);
	const string& getUsername();
	const string& getPassword();
	const User& getInfo();
	void setUsername(string useracc);
	void setPassword(string pass);
	void setInfo(const User& info);
	void readCSV(Node<SchoolYear>*& new_year, Class*& classname, const string& _inputfile);
	Semester& create_semester(int order, const Date& start, const Date& end);
	Course& create_course(string __id, string __name, string __teacher_name, int credits);
	bool add_semester_to_schoolyear(const Semester& new_semester, Node<SchoolYear>*& schoolyear);
	bool add_course_to_semester(const Course& new_course, Node<Semester>*& semester);
	bool remove_course(const Course& course, Node<Semester>*& semester);
	friend bool operator == (const Staff& first, const Staff& second);
	friend bool operator != (const Staff& first, const Staff& second);
};
#endif // !STAFF_H