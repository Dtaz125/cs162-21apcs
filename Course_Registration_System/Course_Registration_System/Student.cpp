#include"Student.h"

Student::Student() : Account() {
	//empty
}
Student::Student(string useracc, string pass, const User& info, string id, string NO) : Account(useracc, pass, info), studentid(id), no(NO) {
	//empty
}
Student::Student(const Student& student) {
	Account::Account(student);
	studentid = student.studentid;
	no = student.no;
	gpa = student.gpa;
	list_of_courses = student.list_of_courses;
}
const string& Student::getStudentID() { 
	return studentid;
}
const string& Student::getNO() { 
	return no; 
}
const Class* Student::getClass() { 
	return student_class;
}
float Student::getGPA() { 
	return gpa; 
}
void Student::setID(const string& id) { 
	studentid = id;
}
void Student::setNO(const string& NO) { 
	no = NO;
}
void Student::setClass(Class* _class) {
	student_class = _class;
}
void Student::calculateGPA() {

}
void Student::attend_course(const Course& course) {
	list_of_courses = new Node<Course>{ course, list_of_courses };
}
void Student::empty_course() {
	Node<Course>* curr = nullptr;
	while (list_of_courses) {
		curr = list_of_courses;
		list_of_courses = list_of_courses->next;
		delete curr;
	}
}
bool operator == (const Student& student_1, const Student& student_2) {
	return student_1.studentid == student_2.studentid;
}
bool operator != (const Student& student_1, const Student& student_2) {
	return student_1.studentid != student_2.studentid;
}