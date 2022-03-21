#pragma once
#include "student.h"
#include "linked_list.h"
#include "Node.h"
#include "iterator.h"
struct Class{
    string name;
    Linked_List<Student> student_list;
    int member;
    Class (){}
    Class (string __name, int __member){
        name = __name;
        member = __member;
    }
};

bool Add_Student(Class &c, Student new_student);
bool set_name(Class &c, string name);

bool set_name(Class &c, string name){
    c.name = name;
    return true;
}
bool Add_Student(Class &c, Student new_student){
    return c.student_list.insert(new_student);
}

