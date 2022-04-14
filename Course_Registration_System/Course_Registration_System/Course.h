#pragma once
#include "Node.h"
#include"Linked_List.h"
#include"Student.h"
#include<string>
#include<utility>
using std::pair;
using std::string;
struct Student;
struct Score {
    string id = "";
    string no = "";
    string fullname = "";
    float final_mark = 0;
    float midterm_mark = 0;
    float total_mark = 0;
    Linked_List<float> other_score;
};
struct Course {
    string id;
    string name;
    string teacher_name;
    string teaching_time;
    int max_student = 50;
    int credits;
    Linked_List<Score> student_score;
    bool is_published = false;

    Course& operator = (Course& course) { return course; }
};

bool operator == (const Course& course_1, const Course& course_2);

bool operator != (const Course& course_1, const Course& course_2);