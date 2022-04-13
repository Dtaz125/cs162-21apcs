#pragma once
#include"Linked_List.h"
#include"Class.h"
#include"Course.h"
#include"Date.h"
#include<utility>
using namespace std;
struct Class;
struct Course;
struct Semester {
	Linked_List<string> list_of_classes; //Just the name of the classes
	Linked_List<pair<string, string>> list_of_courses; //CourseID - Course name
	int order = 0;
	Date start_date = { 0,0,0 };
	Date end_date = { 0,0,0 };
};

bool operator == (const Semester& first, const Semester& second);

bool operator != (const Semester& first, const Semester& second);
//class Semester {
//private:
//    Linked_List<Class> list_of_classes;
//    Linked_List<Course> list_of_courses;
//    int order;
//    Date start_date;
//    Date end_date;
//public:
//    Semester();
//    Semester(const Date& start, const Date& end);
//    int getOrder();
//    const Date& getStartDate();
//    const Date& getEndDate();
//    void setOrder(int k);
//    void setStartDate(const Date& date);
//    void setEndDate(const Date& date);
//    bool add(const Class& _class);
//    bool add(const Course& _course);
//    Node<Course>* contains_course(const Course& _course);
//    Node<Class>* contains_class(const Class& _class);
//    bool remove(const Class& _class);
//    bool remove(const Course& _course);
//    const Iterator<Class> class_begin();
//    const Iterator<Class> class_end();
//    const Iterator<Course> course_begin();
//    const Iterator<Course> course_end();
//    friend bool operator == (const Semester& first, const Semester& second);
//    friend bool operator != (const Semester& first, const Semester& second);
//    ~Semester();
//};
