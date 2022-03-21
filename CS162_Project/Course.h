#pragma once
#include<iostream>
#include "linked_list.h"
#include "Node.h"
#include "iterator.h"
using namespace std;

class Course{
private:
    string id;
    string name;
    string teacher_name;
    string teaching_time;
    int max_student;
    int credits;
    Linked_List<Student> student_list;
    Node student_score;
    bool is_published;

public:
    Course (){}
    Course (string __id, string __name, string __teacher_name, string __teaching_time);

};


