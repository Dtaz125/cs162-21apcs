#pragma once
#include <iostream>
#include "direct.h"
using namespace std;

void outputCourseData(Class& HCMUS) {
    string fileName = "system/courses.txt";
    ofstream f(fileName);
    for (int i = 0; i < HCMUS.numcourse; i++) {
        f << HCMUS.course_list[i];
    }
    f.close();
}

void inputCourseData(Class& HCMUS) {
    HCMUS.course_list = new Course[1000];
    string fileName = "system/courses.txt";
    ifstream f(fileName);
    string id, name, teacher_name, teaching_time;
    int size;
    string st_id, st_name, st_no;
    float final_mark = 0;
    float midterm_mark = 0;
    float total_mark = 0;
    float  other_score[20];
    int number_of_other_score = 0;
    int maxstudent, credit, ispublic;
    while (getline(f, id)) {
        Course co;
        co.student_score.empty_list();
        //// cout << id << " ";
        co.id = id;
        getline(f, name); //// cout << name << " ";
        co.name = name;
        getline(f, teacher_name); // cout << teacher_name << " ";
        co.teacher_name = teacher_name;
        getline(f, teaching_time); // cout << teaching_time << " ";
        co.teaching_time = teaching_time;
        f >> size; // cout << size << endl;
        for (int i = 0; i < size; i++) {
            f.ignore();
            Score s;
            getline(f, st_id); // cout << st_id << " ";
            s.id = st_id;
            getline(f, st_no); // cout << st_no << " ";
            s.no = st_no;
            getline(f, st_name); // // cout << st_name << endl;
            s.fullname = st_name;
            f >> final_mark >> midterm_mark >> total_mark >> number_of_other_score;
            // cout << final_mark << " " << midterm_mark << " " << total_mark << " " << number_of_other_score << endl;
            s.final_mark = final_mark; s.midterm_mark = midterm_mark; s.total_mark = total_mark; s.number_of_other_score = number_of_other_score;
            for (int j = 0; j < number_of_other_score; j++) {
                f >> other_score[j];
                s.other_score[j] = other_score[j];
                // cout << other_score[j] << " ";
            }
            // cout << endl;
            co.student_score.add(s);
        }
        f >> maxstudent >> credit >> ispublic;
        co.max_student = maxstudent; co.credits = credit; co.is_published = ispublic;
        f.ignore();
        // cout << maxstudent << " "<< credit << " "<<ispublic << endl << endl;
        HCMUS.course_list[HCMUS.numcourse++] = co;
    }
    /*while (!f.eof()){
        Course co;
        //co.student_score.empty_list();
        f >> co;
        // cout << co.id << " " << co.name << " " << co.teacher_name << " " << co.teaching_time << " " << co.student_score.size() << endl;
        for (int j = 0; j < co.student_score.size(); j++){
            // cout << co.student_score[j]->data.fullname << endl;
            // cout << co.student_score[j]->data.id << endl;
            // cout << co.student_score[j]->data.no << endl;
            // cout << co.student_score[j]->data.final_mark << endl;
            // cout << co.student_score[j]->data.midterm_mark << endl;
            // cout << co.student_score[j]->data.total_mark << endl;
            // cout << co.student_score[j]->data.number_of_other_score << endl;
            for (int i = 0; i < co.student_score[j]->data.number_of_other_score; i++)
                // cout << co.student_score[j]->data.other_score[i] << " ";
            // cout << endl;
        }
        // cout << HCMUS.course_list.add(co) << endl;
        //co.student_score.empty_list();
    }
//    // cout << co.id << endl;
//    // cout << co.name << endl;
//    // cout << co.student_score.size() << endl;
    //// cout << co.student_score[0]->data.fullname << endl;
    */
    f.close();
    outputCourseData(HCMUS);
}
