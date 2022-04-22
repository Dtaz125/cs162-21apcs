#include"Course.h"
#include <iostream>
using namespace std;
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

ofstream& operator << (ofstream& out_file, Course& course) {
	out_file << course.id << std::endl << course.name
		<< std::endl << course.teacher_name << std::endl << course.teaching_time << std::endl;
	//cout << course.id << " " << course.name << " " << course.student_score.size() << endl;
	out_file << course.student_score.size() << std::endl;
	for (Iterator<Score> iter = course.student_score.begin(); iter != course.student_score.end(); iter++) {
		Score s = *iter;
		out_file << s.id << std::endl << s.no << std::endl << s.fullname << std::endl
			<< s.final_mark << " " << s.midterm_mark << " " << s.total_mark << " " << s.number_of_other_score;
		for (int i = 0; i < s.number_of_other_score; i++) out_file << " " << s.other_score[i];
		out_file << std::endl;
	}
	out_file << course.max_student << " " << course.credits << " " << course.is_published << endl;
	return out_file;
}

ifstream& operator >> (ifstream& in_file, Course& course) {
	in_file.ignore(1, '\n');
	getline(in_file, course.id);
	getline(in_file, course.name);
	getline(in_file, course.teacher_name);
	getline(in_file, course.teaching_time);
	int size;
	in_file >> size;
	in_file.ignore(1, '\n');
	for (int i = 0; i < size; i++) {
		Score s;
		getline(in_file, s.id);
		getline(in_file, s.no);
		getline(in_file, s.fullname);
		in_file >> s.final_mark >> s.midterm_mark >> s.total_mark >> s.number_of_other_score;
		for (int j = 0; j < s.number_of_other_score; j++) in_file >> s.other_score[j];
		course.student_score.add(s);
		in_file.ignore(1, '\n');
	}
	in_file >> course.max_student >> course.credits >> course.is_published;
	return in_file;
}
