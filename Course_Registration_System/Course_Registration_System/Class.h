#pragma once
#include"Iterator.h"
#include"Linked_List.h"
#include "Student.h"
#include<string>
struct Student;
struct Class {
	std::string name;
	Linked_List<Student> student_list;
};
bool operator == (const Class& class_1, const Class& class_2);

bool operator != (const Class& class_1, const Class& class_2);
//class Class {
//private:
//    string name;
//    Linked_List<Student> student_list;
//public:
//    Class();
//    Class(const string& _name, int _member);
//    Class(const Class& class_A);
//    int getMember();
//    const string& getName();
//    void setName(const string& _name);
//    bool add_student(const Student& student);
//    Node<Student>* contains_student(const Student& student);
//    bool remove_student(const Student& student);
//    friend bool operator == (const Class& class_1, const Class& class_2);
//    friend bool operator != (const Class& class_1, const Class& class_2);
//    const Iterator<Student> student_begin();
//    const Iterator<Student> student_end();
// 
//    ~Class();
//};

