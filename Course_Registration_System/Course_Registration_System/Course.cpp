#include"Course.h"

bool operator == (const Course& course_1, const Course& course_2) {
    return course_1.id == course_2.id;
}
bool operator != (const Course& course_1, const Course& course_2) {
    return course_1.id != course_2.id;
}
bool operator == (const Score& score_1, const Score& score_2) {
    return score_1.id == score_2.id;
}

bool operator != (const Score& score_1, const Score& score_2) {
    return score_1.id != score_2.id;
}

//ofstream& operator << (ofstream& out_file, Student& student) {
//	return out_file;
//}

ifstream& operator >> (ifstream& in_file, Course& Course) {
	in_file.ignore(1, '\n');
	getline(in_file, Course.id);
	getline(in_file, Course.name);
	getline(in_file, Course.teacher_name);
	getline(in_file, Course.teaching_time);
	return in_file;
}