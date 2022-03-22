#include"Course.h"
#include"Student.h"
Course::Course(string __id, string __name, string __teacher_name, string __teaching_time) : id(__id), 
    name(__name), teacher_name(__teacher_name), teaching_time(__teaching_time) {
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
const string& Course::getTeachingTime() {
    return teaching_time;
}
int Course::getStudent() { 
    return current_student;
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
void Course::setTeachingTime(const string& _time) { 
    teaching_time = _time;
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
    student_list = new Node<Student>{ student, student_list };
    current_student++;
}
void Course::add_score(int k) {
    student_score = new Node<int>{ k, student_score };
}
Node<Student>* Course::contains(const Student& student) {
    Node<Student>* curr = student_list;
    while (curr && curr->data != student)
        curr = curr->next;
    return curr;
}
bool Course::remove(const Student& student) {
    Node<Student>* curr = student_list, * prev = nullptr;
    while (curr && curr->data != student) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) return false;
    if (!prev) student_list = student_list->next;
    else prev->next = curr->next;
    delete curr;
    current_student--;
    return true;
}
void Course::empty_student_list() {
    Node<Student>* curr = nullptr;
    while (student_list) {
        curr = student_list;
        student_list = student_list->next;
        delete curr;
    }
}
void Course::empty_score_list() {
    Node<int>* curr = nullptr;
    while (student_score) {
        curr = student_score;
        student_score = student_score->next;
        delete curr;
    }
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
    Node<Student>* curr = course.student_list;
    Node<int>* curr_1 = course.student_score;
    while (curr) {
        add_student(curr->data);
        curr = curr->next;
    }
    while (curr_1) {
        add_score(curr_1->data);
        curr_1 = curr_1->next;
    }
    return *this;
}

Course::~Course() {
    empty_student_list();
    empty_score_list();
}