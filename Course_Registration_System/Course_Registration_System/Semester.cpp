#include"Semester.h"

Semester::Semester(const Date& start, const Date& end) : start_date(start), end_date(end) {
    order = -1;
}
int Semester::getOrder() { 
    return order; 
}
const Date& Semester::getStartDate() { 
    return start_date;
}
const Date& Semester::getEndDate() { 
    return end_date;
}
void Semester::setOrder(int k) { 
    order = k;
}
void Semester::setStartDate(const Date& date) { 
    start_date = date;
}
void Semester::setEndDate(const Date& date) { 
    end_date = date;
}
bool Semester::add(const Class& _class) {
    return list_of_classes.add(_class);
}
bool Semester::add(const Course& _course) {
    return list_of_courses.add(_course);
}
Node<Course>* Semester::contains_course(const Course& _course) {
    return list_of_courses.contains(_course);
}
Node<Class>* Semester::contains_class(const Class& _class) {
    return list_of_classes.contains(_class);
}
bool Semester::remove(const Class& _class) {
    return list_of_classes.remove(_class);
}

bool Semester::remove(const Course& _course) {
    return list_of_courses.remove(_course);
}

const Iterator<Class> Semester::class_begin() {
    return list_of_classes.begin();
}

const Iterator<Class> Semester::class_end() {
    return list_of_classes.end();
}

const Iterator<Course> Semester::course_begin() {
    return list_of_courses.begin();
}

const Iterator<Course> Semester::course_end() {
    return list_of_courses.end();
}

bool operator == (const Semester& first, const Semester& second) {
    return first.order == second.order;
}

bool operator != (const Semester& first, const Semester& second) {
    return first.order != second.order;
}
Semester::~Semester() {
    list_of_classes.empty_list();
    list_of_courses.empty_list();
}