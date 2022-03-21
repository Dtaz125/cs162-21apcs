#pragma once
#ifndef CLASS_H
#define CLASS_H
#include "Node.h"
#include "Student.h"
struct Class {
    string name;
    Node<Student>* student_list;
    int member;
};

bool add_student(const Student& student, Class& _class);

bool contains_student(const Student& student, const Class& _class);

bool remove_student(const Student& student, Class& _class);

bool operator == (const Class& class_1, const Class& class_2);

bool operator != (const Class& class_1, const Class& class_2);
#endif // !CLASS_H
