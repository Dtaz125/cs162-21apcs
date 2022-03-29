#include"Course.h"
#include"Student.h"
Course::Course(string __id, string __name, string __teacher_name) : id(__id), 
    name(__name), teacher_name(__teacher_name) {
    //empty
}
const string& Course::getID() { 
    return id;
}
const string& Course::getCourseName() { 
    return name;
}
const string& Course::getTeacherName() { 
    return teacher_name; 
}
int Course::getStudent() { 
    return student_list.size();
}
int Course::getMaxStudent() { 
    return max_student;
}
int Course::getCredits() { 
    return credits;
}
bool Course::isPublished() { 
    return is_published;
}
void Course::setID(const string& _id) { 
    id = _id;
}
void Course::setCourseName(const string& _name) { 
    name = _name;
}
void Course::setTeacherName(const string& _name) { 
    teacher_name = _name;
}
void Course::setTeachingTime(const string& time_1, const string& time_2) { 
    teaching_time.add(time_1);
    teaching_time.add(time_2);
}
void Course::setTeachingTime(const Linked_List<string>& list) {
    teaching_time = list;
}
void Course::setMaxStudent(int _number) { 
    max_student = _number;
}
void Course::setCredits(int _credit) { 
    credits = _credit;
}
void Course::publishCourse() { 
    is_published = true;
}
void Course::add_student(const Student& student) {
    student_list.add(student);
}
void Course::add_score(int k) {
    student_score.add(k);
}
Node<Student>* Course::contains(const Student& student) {
    return student_list.contains(student);
}
bool Course::remove(const Student& student) {
    return student_list.remove(student);
}
void Course::empty_student_list() {
    student_list.empty_list();
}
void Course::empty_score_list() {
    student_score.empty_list();
}
bool operator == (const Course& course_1, const Course& course_2) {
    return course_1.id == course_2.id;
}
bool operator != (const Course& course_1, const Course& course_2) {
    return course_1.id != course_2.id;
}
Course& Course::operator = (const Course& course) {
    if (this == &course) return *this;
    empty_student_list();
    empty_score_list();
    setID(course.id);
    setCourseName(course.name);
    setCredits(course.credits);
    setMaxStudent(course.max_student);
    setTeacherName(course.teacher_name);
    setTeachingTime(course.teaching_time);
    is_published = course.is_published;
    student_list = course.student_list;
    student_score = course.student_score;
    return *this;
}
const Iterator<string> Course::time_begin() {
    return teaching_time.begin();
}
const Iterator<string> Course::time_end() {
    return teaching_time.end();
}
const Iterator<Student> Course::student_begin() {
    return student_list.begin();
}

const Iterator<Student> Course::student_end() {
    return student_list.end();
}

const Iterator<int> Course::score_begin() {
    return student_score.begin();
}

const Iterator<int> Course::score_end() {
    return student_score.end();
}

Course::~Course() {
    empty_student_list();
    empty_score_list();
}