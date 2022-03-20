#pragma once
#include "student.h"
#include "linked_list.h"
#include "Node.h"
#include "iterator.h"
struct Class{
    string name;
    Linked_List<Student> student_list;
    int member;
};

