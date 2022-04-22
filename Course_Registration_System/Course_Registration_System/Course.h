#pragma once
#include "Node.h"
#include"Linked_List.h"
#include"Student.h"
#include<string>
#include<utility>
#include<fstream>
using std::pair;
using std::string;
using std::getline;
struct Student;
struct Score {
    string id = "";
    string no = "";
    string fullname = "";
    float final_mark = 0;
    float midterm_mark = 0;
    float total_mark = 0;
    float  other_score[20];
    int number_of_other_score = 0;
    //Score& operator = (Score& scr) { return scr; }
};
struct Course {
    string id = "";
    string name = "";
    string teacher_name = "";
    string teaching_time = "";
    int max_student = 50;
    int credits = 4;
    Linked_List<Score> student_score;
    bool is_published = false;

    //Course& operator = (Course& course) { return course; }
};

bool operator == (const Course& course_1, const Course& course_2);

bool operator != (const Course& course_1, const Course& course_2);

bool operator == (const Score& score_1, const Score& score_2);

bool operator != (const Score& score_1, const Score& score_2);

ofstream& operator << (ofstream& out_file, Course& course);

ifstream& operator >> (ifstream& in_file, Course& course);