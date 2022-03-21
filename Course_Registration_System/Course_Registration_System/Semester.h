#pragma once
#ifndef SEMESTER_H
#define SEMESTER_H
#include"Node.h"
#include"Class.h"
#include"Course.h"
#include"Date.h"
using namespace std;

class Semester {
private:
    Node<Class>* list_of_classes;
    Node<Course>* list_of_courses;
    int order;
    Date start_date;
    Date end_date;
public:
    Semester(const Date& start, const Date& end);
    int getOrder();
    const Date& getStartDate();
    const Date& getEndDate();
    void setOrder(int k);
    void setStartDate(const Date& date);
    void setEndDate(const Date& date);
    void insert_class(const Class& _class);
    void insert_course(const Course& _course);
    Node<Course>* contains_course(const Course& _course);
    Node<Class>* contains_class(const Class& _class);
    bool remove_class(const Class& _class);
};
#endif // !SEMESTER_H
