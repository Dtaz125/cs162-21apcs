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
};

