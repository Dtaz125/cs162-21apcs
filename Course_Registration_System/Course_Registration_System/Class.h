#ifndef CLASS_H
#define CLASS_H
#include"Iterator.h"
#include"Linked_List.h"
#include "Student.h"
class Student;
class Class {
private:
    string name;
    Linked_List<Student> student_list;
public:
    Class();
    Class(const string& _name, int _member);
    Class(const Class& class_A);
    int getMember();
    const string& getName();
    void setName(const string& _name);
    bool add_student(const Student& student);
    Node<Student>* contains_student(const Student& student);
    bool remove_student(const Student& student);
    friend bool operator == (const Class& class_1, const Class& class_2);
    friend bool operator != (const Class& class_1, const Class& class_2);
    const Iterator<Student> student_begin();
    const Iterator<Student> student_end();
};
#endif // !CLASS_H
