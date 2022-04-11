#include"SchoolYear.h"

SchoolYear::SchoolYear(const string& _name) : name(_name) {

}
const string& SchoolYear::getName() {
	return name;
}
bool SchoolYear::contains(const Semester& _semester) {
	return list_of_semesters.contains(_semester) != nullptr;
}
Node<Semester>* SchoolYear::access_semester(const Semester& _semester) {
	return list_of_semesters.contains(_semester);
}
bool SchoolYear::add(const Semester& _semester) {
	return list_of_semesters.add(_semester);
}
void SchoolYear::add(const Linked_List<Semester>& list) {
	list_of_semesters.add(list);
}
bool SchoolYear::remove(const Semester& _semester) {
	return list_of_semesters.remove(_semester);
}
void SchoolYear::remove(const Linked_List<Semester>& list) {
	list_of_semesters.remove(list);
}
bool operator == (const SchoolYear& first, const SchoolYear& second) {
	return first.name == second.name;
}
bool operator != (const SchoolYear& first, const SchoolYear& second) {
	return first.name != second.name;
}
const Iterator<Semester> SchoolYear::semester_begin() {
	return list_of_semesters.begin();
}
const Iterator<Semester> SchoolYear::semester_end() {
	return list_of_semesters.end();
}
SchoolYear::~SchoolYear() {
	list_of_semesters.empty_list();
}
