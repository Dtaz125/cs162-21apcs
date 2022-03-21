#pragma once
#include "Node.h"
#include"Student.h"
class Course{
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
    Course (string __id, string __name, string __teacher_name, string __teaching_time): id(__id), name(__name), teacher_name(__teacher_name),
        teaching_time(__teaching_time){}
    const string& getID() { return id; }
    const string& getCourseName() { return name; }
    const string& getTeacherName() { return teacher_name; }
    const string& getTeachingTime() { return teaching_time; }
    int getStudent() { return current_student; }
    int getMaxStudent() { return max_student; }
    int getCredits() { return credits; }
    bool isPublished() { return is_published; }
    void setID(const string& _id) { id = _id; }
    void setCourseName(const string& _name) { name = _name; }
    void setTeacherName(const string& _name) { teacher_name = _name; }
    void setTeachingTime(const string& _time) { teaching_time = _time; }
    void setMaxStudent(int _number) { max_student = _number; }
    void setCredits(int _credit) { credits = _credit; }
    void publishCourse() { is_published = true; }
    void add_student(const Student& student) {
        student_list = new Node<Student>{ student, student_list };
        current_student++;
    }
    void add_score(int k) {
        student_score = new Node<int>{ k, student_score };
    }
    Node<Student>* contains(const Student& student) {
        Node<Student>* curr = student_list;
        while (curr && curr->data != student)
            curr = curr->next;
        return curr;
    }
    bool remove(const Student& student) {
        Node<Student>* curr = student_list, * prev = nullptr;
        while (curr && curr->data != student) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) return false;
        if (!prev) student_list = student_list->next;
        else prev->next = curr->next;
        delete curr;
        current_student--;
        return true;
    }
    void empty_student_list() {
        Node<Student>* curr = nullptr;
        while (student_list) {
            curr = student_list;
            student_list = student_list->next;
            delete curr;
        }
    }
    void empty_score_list() {
        Node<int>* curr = nullptr;
        while (student_score) {
            curr = student_score;
            student_score = student_score->next;
            delete curr;
        }
    }
    friend bool operator == (const Course& course_1, const Course& course_2) {
        return course_1.id == course_2.id;
    }
    friend bool operator != (const Course& course_1, const Course& course_2) {
        return course_1.id != course_2.id;
    }
    Course& operator = (const Course& course) {
        if (this == &course) return *this;
        empty_student_list();
        empty_score_list();
        setID(course.id);
        setCourseName(course.name);
        setCredits(course.credits);
        setMaxStudent(course.max_student);
        setTeacherName(course.teacher_name);
        setTeachingTime(course.teaching_time);
        is_published = course.is_published;
        Node<Student>* curr = course.student_list;
        Node<int>* curr_1 = course.student_score;
        while (curr) {
            add_student(curr->data);
            curr = curr->next;
        }
        while (curr_1) {
            add_score(curr_1->data);
            curr_1 = curr_1->next;
        }
        return *this;
    }

    ~Course() {
        empty_student_list();
        empty_score_list();
    }
};

