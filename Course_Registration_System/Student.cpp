#include"Student.h"

bool operator == (const Student& student_1, const Student& student_2) {
	return student_1.id == student_2.id;
}
bool operator != (const Student& student_1, const Student& student_2) {
	return student_1.id != student_2.id;
}

ofstream& operator << (ofstream& out_file, Student& student) {
	out_file << std::endl;
	out_file << student.username << std::endl << student.password << std::endl << student.user_info.firstname << std::endl << student.user_info.lastname << std::endl << student.user_info.social_id << std::endl
		<< student.id << std::endl << student.no << std::endl << student.student_class << std::endl;
	out_file << student.list_of_courses.size() << std::endl;
	for (Iterator<pair<string, string>> iter = student.list_of_courses.begin(); iter != student.list_of_courses.end(); iter++) {
		pair<string, string> p = *iter;
		out_file << p.first << std::endl << p.second << std::endl;
	}
	out_file << student.user_info.birth.day << " " << student.user_info.birth.month << " " << student.user_info.birth.year << " " << student.user_info.gender << " "<< student.gpa;
	return out_file;
}

ifstream& operator >> (ifstream& in_file, Student& student) {
	in_file.ignore(1, '\n');
	getline(in_file, student.username);
	getline(in_file, student.password);
	getline(in_file, student.user_info.firstname);
	getline(in_file, student.user_info.lastname);
	getline(in_file, student.user_info.social_id);
	getline(in_file, student.id);
	getline(in_file, student.no);
	getline(in_file, student.student_class);
	int size;
	in_file >> size;
	in_file.ignore(1, '\n');
	for (int i = 0; i < size; i++) {
		pair<string, string> p;
		string id, name;
		getline(in_file, id);
		getline(in_file, name);
		p = std::make_pair(id, name);
		student.list_of_courses.add(p);
	}
	in_file>> student.user_info.birth.day >> student.user_info.birth.month
		>> student.user_info.birth.year >> student.user_info.gender>>student.gpa;
	return in_file;
}
