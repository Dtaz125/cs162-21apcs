#include"Class.h"
Class::Class() {

}
Class::Class(const string& _name, int _member) : name(_name), member(_member) {

}

Class::Class(const Class& class_A):name(class_A.name), member(class_A.member), student_list(class_A.student_list) {

}
int Class::getMember() { 
    return member;
}
const string& Class::getName() {
    return name;
}

Node<Student>* Class::getStudentList() { 
    return student_list; 
}
void Class::setMember(int _member) {
    member = _member;
}
void Class::setName(const string& _name) {
    name = _name;
}
bool Class::add_student(const Student& student) {
    if (contains_student(student)) return false;
    Node<Student>* newNode = new Node<Student>{ student, nullptr };
    newNode->next = student_list;
    student_list = newNode;
    return true;
}

bool Class::contains_student(const Student& student) {
    Node<Student>* curr = student_list;
    while (curr && curr->data != student)
        curr = curr->next;
    return curr != nullptr;
}

bool Class::remove_student(const Student& student) {
    Node<Student>* curr = student_list, * prev = nullptr;
    while (curr && curr->data != student) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) return false;
    if (!prev) student_list = student_list->next;
    else prev->next = curr->next;
    delete curr;
    return true;
}

bool operator == (const Class& class_1, const Class& class_2){
    return class_1.name == class_2.name;
}

bool operator != (const Class& class_1, const Class& class_2) {
    return class_1.name != class_2.name;
}