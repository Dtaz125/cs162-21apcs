#pragma once
#ifndef COURSE_H
#define COURSE_H
#include "Node.h"
#include"Student.h"
class Course {
private:
    string id;
    string name;
    string teacher_name;
    string teaching_time;
    int max_student = 50;
    int current_student = 0;
    int credits;
    Node<Student>* student_list = nullptr;
    Node<int>* student_score = nullptr;
    bool is_published = false;
public:
    Course(string __id, string __name, string __teacher_name, string __teaching_time);
    const string& getID();
    const string& getCourseName();
    const string& getTeacherName();
    const string& getTeachingTime();
    int getStudent();
    int getMaxStudent();
    int getCredits();
    bool isPublished();
    void setID(const string& _id);
    void setCourseName(const string& _name);
    void setTeacherName(const string& _name);
    void setTeachingTime(const string& _time);
    void setMaxStudent(int _number);
    void setCredits(int _credit);
    void publishCourse();
    void add_student(const Student& student);
    void add_score(int k);
    Node<Student>* contains(const Student& student);
    bool remove(const Student& student);
    void empty_student_list();
    void empty_score_list();
    friend bool operator == (const Course& course_1, const Course& course_2);
    friend bool operator != (const Course& course_1, const Course& course_2);
    Course& operator = (const Course& course);
    ~Course();
};
#endif // !COURSE_H
