#include"Class.h"
Class::Class() {

}
Class::Class(const string& _name, int _member) : name(_name){

}

Class::Class(const Class& class_A):name(class_A.name), student_list(class_A.student_list) {

}
int Class::getMember() {
    return student_list.size();
}
const string& Class::getName() {
    return name;
}

void Class::setName(const string& _name) {
    name = _name;
}

bool Class::add_student(const Student& student) {
    return student_list.add(student);
}

Node<Student>* Class::contains_student(const Student& student) {
    return student_list.contains(student);
}

bool Class::remove_student(const Student& student) {
    return student_list.remove(student);
}

bool operator == (const Class& class_1, const Class& class_2){
    return class_1.name == class_2.name;
}

bool operator != (const Class& class_1, const Class& class_2) {
    return class_1.name != class_2.name;
}

const Iterator<Student> Class::student_begin() {
    return student_list.begin();
}
const Iterator<Student> Class::student_end() {
    return student_list.end();
}
Class::~Class() {
    student_list.empty_list();
    name = "";
}
