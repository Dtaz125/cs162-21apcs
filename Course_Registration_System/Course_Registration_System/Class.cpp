#include"Class.h"
Class::Class() {

}
Class::Class(const string& _name, int _member) : name(_name), member(_member) {
    
}

Class::Class(const Class& class_A):name(class_A.name), student_list(class_A.student_list) {
    
}
int Class::getMember() { 
    return member;                  //i changed this function to return a new int variable 'member' to represent the total students in a given class
                                    //because there was no student_list.size() function anywhere in students.h
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