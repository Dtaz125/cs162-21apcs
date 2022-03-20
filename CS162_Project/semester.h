#pragma once
#include<iostream>
#include "date.h"
#include "course.h"
#include "class.h"
#include "linked_list.h"
#include "Node.h"
#include "iterator.h"
using namespace std;

class semester{
private:
    Linked_List<Class> list_of_classes;
    Linked_List<Course> list_of_courses;
    int order;
    Date start_date;
    Date end_date;
public:
    semester(){}
    bool Add_Class(Class new_class);
    bool Add_Course(Course new_course);
    bool Modify(int dd, int mm, int yyyy, bool isend = false);
    bool set_order(int __order);

    bool Add_Class(Class new_class){
        return list_of_classes.insert(new_class);
    }

    bool Add_Course(Course new_course){
        return list_of_courses.insert(new_course);
    }
    bool Modify(int dd, int mm, int yyyy, bool isend = false){
        Date tmp = {dd, mm, yyyy};
        if (!valid(tmp)) return false;
        if (!isend) start_date = tmp;
        else end_date = tmp;
        return true;
    }
    bool set_order(int __order){
        if (__order > 0){
            order = __order;
            return true;
        }
    }
};

