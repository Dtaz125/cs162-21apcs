#ifndef COURSE_H
#define COURSE_H
#include "Node.h"
#include"Linked_List.h"
#include"Student.h"
#include<utility>
using std::pair;
class Student;
class Course {
private:
    string id;
    string name;
    string teacher_name;
    string teaching_time;
    int max_student = 50;
    int credits;
    Linked_List<Student> student_list;
    Linked_List<pair<string,int>> student_score;
    bool is_published = false;
public:
    Course(string __id, string __name, string __teacher_name);
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
    void add_score(pair<string,int> k);
    void update_score_board(Linked_List<int>& scorelist);
    Node<Student>* contains(const Student& student);
    bool remove(const Student& student);
    void empty_student_list();
    void empty_score_list();
    friend bool operator == (const Course& course_1, const Course& course_2);
    friend bool operator != (const Course& course_1, const Course& course_2);
    Course& operator = (const Course& course);
    const Iterator<Student> student_begin();
    const Iterator<Student> student_end();
    const Iterator<pair<string, int>> score_begin();
    const Iterator<pair<string, int>> score_end();
    ~Course();
};
#endif // !COURSE_H
