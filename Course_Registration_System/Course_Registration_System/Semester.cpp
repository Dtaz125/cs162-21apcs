#include"Semester.h"

Semester::Semester(const Date& start, const Date& end) : start_date(start), end_date(end) {
    order = -1;
}
int Semester::getOrder() { 
    return order; 
}
const Node<Class>* Semester::getClasses() {
    return list_of_classes;
}
const Node<Course>* Semester::getCourses() {
    return list_of_courses;
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
void Semester::insert_class(const Class& _class) {
    list_of_classes = new Node<Class>{ _class, list_of_classes };
}
void Semester::insert_course(const Course& _course) {
    list_of_courses = new Node<Course>{ _course, list_of_courses };
}
Node<Course>* Semester::contains_course(const Course& _course) {
    Node<Course>* curr = list_of_courses;
    while (curr && curr->data != _course)
        curr = curr->next;
    return curr;
}
Node<Class>* Semester::contains_class(const Class& _class) {
    Node<Class>* curr = list_of_classes;
    while (curr && curr->data != _class)
        curr = curr->next;
    return curr;
}
bool Semester::remove_class(const Class& _class) {
    Node<Class>* curr = list_of_classes, * prev = nullptr;
    while (curr && curr->data != _class) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) return false;
    if (!prev) list_of_classes = list_of_classes->next;
    else prev->next = curr->next;
    delete curr;
    return true;
}