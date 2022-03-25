#ifndef SEMESTER_H
#define SEMESTER_H
#include"Linked_List.h"
#include"Class.h"
#include"Course.h"
#include"Date.h"
using namespace std;
class Student;
class Course;
class Class;
class Semester {
private:
    Linked_List<Class> list_of_classes;
    Linked_List<Course> list_of_courses;
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
    void add(const Class& _class);
    void add(const Course& _course);
    Node<Course>* contains_course(const Course& _course);
    Node<Class>* contains_class(const Class& _class);
    bool remove(const Class& _class);
    bool remove(const Course& _course);
    const Iterator<Class> class_begin();
    const Iterator<Class> class_end();
    const Iterator<Course> course_begin();
    const Iterator<Course> course_end();
    friend bool operator == (const Semester& first, const Semester& second);
    friend bool operator != (const Semester& first, const Semester& second);
    ~Semester();
};
#endif // !SEMESTER_H
