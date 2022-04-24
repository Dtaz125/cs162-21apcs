#pragma once
#include"User.h"
#include"Linked_List.h"
#include<utility>
#include<fstream>
using std::pair;
using std::ofstream;
using std::ifstream;
struct Course;
struct Class;
struct Student {
	string username = "";
	string password = "";
	User user_info = { "","",1,"", {0,0,0} };
	string id = "";
	string no = "";
	float gpa = 0;
	string student_class = ""; //name of the class
	int numcourse = 0;
	pair<string, string>* list_of_courses; //CourseID - Full name
	//Student& operator = (Student& stu) { return stu; }
	void init() {
		list_of_courses = new pair <string, string>[numcourse + 10];
	}
    bool addCourse(string id, string fullname){
        for (int i = 0; i < numcourse; i++) if (list_of_courses[i].first == id)
            return false;
        int n = numcourse++;
        list_of_courses[n] = {id, fullname};
        return true;
    }

};
bool operator == (const Student& student_1, const Student& student_2);

bool operator != (const Student& student_1, const Student& student_2);

ofstream& operator << (ofstream& out_file, Student& student);

ifstream& operator >> (ifstream& in_file, Student& student);
