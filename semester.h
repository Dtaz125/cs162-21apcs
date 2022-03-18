#pragma once
#include<iostream>
#include "date.h"
#include "course.h"
#include "class.h"
using namespace std;

class semester{
private:
    Class* list_of_classes;
    Course* list_of_courses;
    int order;
    Date start_date;
    Date end_date;
public:
};

