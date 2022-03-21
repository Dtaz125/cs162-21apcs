#pragma once
#pragma once
#include"Node.h"
#include"Class.h"
#include"Course.h"
#include"Date.h"
using namespace std;

class Semester{
private:
    Node<Class>* list_of_classes;
    Node<Course>* list_of_courses;
    int order;
    Date start_date;
    Date end_date;
public:
    Semester(const Date& start, const Date& end): start_date(start), end_date(end){}
    int getOrder() { return order; }
    const Date& getStartDate() { return start_date; }
    const Date& getEndDate() { return end_date; }
    void setOrder(int k) { order = k; }
    void setStartDate(const Date& date) { start_date = date; }
    void setEndDate(const Date& date) { end_date = date; }
    void insert_class(const Class& _class) {
        list_of_classes = new Node<Class>{ _class, list_of_classes };
    }
    void insert_course(const Course& _course) { 
        list_of_courses = new Node<Course>{ _course, list_of_courses };
    }
    Node<Course>* contains_course(const Course& _course) {
        Node<Course>* curr = list_of_courses;
        while (curr && curr->data != _course)
            curr = curr->next;
        return curr;
    }
    Node<Class>* contains_class(const Class& _class) {
        Node<Class>* curr = list_of_classes;
        while (curr && curr->data != _class)
            curr = curr->next;
        return curr;
    }
    bool remove_class(const Class& _class) {
        Node<Class>* curr = list_of_classes, * prev = nullptr;
        while (curr && curr->data != _class) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) return false;
        if (!prev) list_of_classes = list_of_classes->next;
        else prev->next = curr->next;
        delete curr;
        return true;
    }
};

