#include"RegistrationSystem.h"

RegistrationSystem::RegistrationSystem(const string& _name): name(_name){
	//empty
}
int RegistrationSystem::count_staff() {
	return academic_staffs.size();
}
int RegistrationSystem::count_student() {
	return students.size();
}
const string& RegistrationSystem::getName() {
	return name;
}
Node<Student>* RegistrationSystem::access_student(const Student& _student) {
	return students.contains(_student);
}
Node<Staff>* RegistrationSystem::access_staff(const Staff& _staff) {
	return academic_staffs.contains(_staff);
}
Node<SchoolYear>* RegistrationSystem::access_year(const SchoolYear& _year) {
	return schoolyears.contains(_year);
}
bool RegistrationSystem::add(const Staff& new_staff) {
	return academic_staffs.add(new_staff);
}
void RegistrationSystem::add(const Linked_List<Staff>& staff_list) {
	academic_staffs.add(staff_list);
}
bool RegistrationSystem::add(const Student& new_student) {
	return students.add(new_student);
}
void RegistrationSystem::add(const Linked_List<Student>& student_list) {
	students.add(student_list);
}
bool RegistrationSystem::add(const SchoolYear& new_year) {
	return schoolyears.add(new_year);
}
void RegistrationSystem::add(const Linked_List<SchoolYear>& year_list) {
	schoolyears.add(year_list);
}
void RegistrationSystem::remove(const Staff& new_staff) {
	academic_staffs.remove(new_staff);
}
void RegistrationSystem::remove(const Linked_List<Staff>& staff_list) {
	academic_staffs.remove(staff_list);
}
void RegistrationSystem::remove(const Student& new_student) {
	students.remove(new_student);
}
void RegistrationSystem::remove(const Linked_List<Student>& student_list) {
	students.remove(student_list);
}
void RegistrationSystem::remove(const SchoolYear& new_year) {
	schoolyears.remove(new_year);
}
void RegistrationSystem::remove(const Linked_List<SchoolYear>& year_list) {
	schoolyears.remove(year_list);
}
const Iterator<Student> RegistrationSystem::student_begin() {
	return students.begin();
}
const Iterator<Student> RegistrationSystem::student_end() {
	return students.end();
}
const Iterator<Staff> RegistrationSystem::staff_begin() {
	return academic_staffs.begin();
}
const Iterator<Staff> RegistrationSystem::staff_end() {
	return academic_staffs.end();
}
const Iterator<SchoolYear> RegistrationSystem::year_begin() {
	return schoolyears.begin();
}
const Iterator<SchoolYear> RegistrationSystem::year_end() {
	return schoolyears.end();
}
RegistrationSystem::~RegistrationSystem() {
	students.empty_list();
	academic_staffs.empty_list();
	schoolyears.empty_list();
}