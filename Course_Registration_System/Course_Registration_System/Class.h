#ifndef CLASS_H
#define CLASS_H
#include "Node.h"
#include "Student.h"
class Student;
class Class {
private:
    string name;
    Node<Student>* student_list;
    int member = 0;
public:
    Class();
    Class(const string& _name, int _member);
    Class(const Class& class_A);
    int getMember();
    const string& getName();
    Node<Student>* getStudentList();
    void setMember(int _member);
    void setName(const string& _name);
    bool add_student(const Student& student);
    bool contains_student(const Student& student);
    bool remove_student(const Student& student);
    friend bool operator == (const Class& class_1, const Class& class_2);
    friend bool operator != (const Class& class_1, const Class& class_2);
};
#endif // !CLASS_H
