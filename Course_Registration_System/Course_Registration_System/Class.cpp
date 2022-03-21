#include"Class.h"

bool add_student(const Student& student, Class& _class) {
    if (contains_student(student, _class)) return false;
    Node<Student>* newNode = new Node<Student>{ student, nullptr };
    newNode->next = _class.student_list;
    _class.student_list = newNode;
    return true;
}

bool contains_student(const Student& student, const Class& _class) {
    Node<Student>* curr = _class.student_list;
    while (curr && curr->data != student)
        curr = curr->next;
    return curr != nullptr;
}

bool remove_student(const Student& student, Class& _class) {
    Node<Student>* curr = _class.student_list, * prev = nullptr;
    while (curr && curr->data != student) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) return false;
    if (!prev) _class.student_list = _class.student_list->next;
    else prev->next = curr->next;
    delete curr;
    return true;
}

bool operator == (const Class& class_1, const Class& class_2) {
    return class_1.name == class_2.name;
}

bool operator != (const Class& class_1, const Class& class_2) {
    return class_1.name != class_2.name;
}