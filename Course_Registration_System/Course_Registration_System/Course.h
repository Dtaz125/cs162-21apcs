#ifndef COURSE_H
#define COURSE_H
#include "Node.h"
#include"Linked_List.h"
#include"Student.h"
class Student;
class Course {
private:
    string id;
    string name;
    string teacher_name;
    Linked_List<string> teaching_time;
    int max_student = 50;
    int credits;
    Linked_List<Student> student_list;
    Linked_List<int> student_score;
    bool is_published = false;
public:
    Course(string __id, string __name, string __teacher_name);
    const string& getID();
    const string& getCourseName();
    const string& getTeacherName();
    int getStudent();
    int getMaxStudent();
    int getCredits();
    bool isPublished();
    void setID(const string& _id);
    void setCourseName(const string& _name);
    void setTeacherName(const string& _name);
    void setTeachingTime(const string& time_1, const string& time_2);
    void setTeachingTime(const Linked_List<string>& list);
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
    const Iterator<string> time_begin();
    const Iterator<string> time_end();
    const Iterator<Student> student_begin();
    const Iterator<Student> student_end();
    const Iterator<int> score_begin();
    const Iterator<int> score_end();
    ~Course();
};
#endif // !COURSE_H
