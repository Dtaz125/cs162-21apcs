#include"Staff.h"

Staff::Staff() {
	//empty
}
Staff::Staff(string useracc, string pass, const User& info): username(useracc), password(pass), user_info(info){
	//empty
}
Staff::Staff(const Staff& staff) : username(staff.username), password(staff.password), user_info(staff.user_info) {
	//empty
}
const string& Staff::getUsername() {
	return username;
}
const string& Staff::getPassword() {
	return password;
}
const User& Staff::getInfo() {
	return user_info;
}
void Staff::setUsername(string useracc) {
	username = useracc;
}
void Staff::setPassword(string pass) {
	password = pass;
}
void Staff::setInfo(const User& info) {
	user_info = info;
}
Semester& Staff::create_semester(int order, const Date& start, const Date& end) {
	Semester new_semester(start, end);
	new_semester.setOrder(order);
	return new_semester;
}
Course& Staff::create_course(string __id, string __name, string __teacher_name, int credits) {
	Course new_course(__id, __name, __teacher_name);
	new_course.setCredits(credits);
	return new_course;
}

bool Staff::add_semester_to_schoolyear(const Semester& new_semester, Node<SchoolYear>*& schoolyear) {
	return schoolyear->data.add(new_semester);
}
bool Staff::add_course_to_semester(const Course& new_course, Node<Semester>*& semester) {
	return semester->data.add(new_course);
}
bool Staff::remove_course(const Course& course, Node<Semester>*& semester) {
	return semester->data.remove(course);
}
bool operator == (const Staff& first, const Staff& second) {
	return first.user_info.social_id == second.user_info.social_id;
}
bool operator != (const Staff& first, const Staff& second) {
	return first.user_info.social_id != second.user_info.social_id;
}

