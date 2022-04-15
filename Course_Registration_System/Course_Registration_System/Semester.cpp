#include"Semester.h"
bool operator == (const Semester& first, const Semester& second) {
    return first.order == second.order;
}

bool operator != (const Semester& first, const Semester& second) {
    return first.order != second.order;
}

ofstream& operator << (ofstream& out_file, Semester& semester) {
	out_file << semester.list_of_classes.size() << endl;
	for (Iterator<string> iter = semester.list_of_classes.begin(); iter != semester.list_of_classes.end(); iter++) {
		string p = *iter;
		out_file << p << endl;
	}
	out_file << semester.list_of_courses.size() << endl;
	for (Iterator<pair<string, string>> iter = semester.list_of_courses.begin(); iter != semester.list_of_courses.end(); iter++) {
		pair<string, string> p = *iter;
		out_file << p.first << endl << p.second << endl;
	}
	out_file << semester.order << endl;
	out_file << semester.start_date.day << " " << semester.start_date.month << " " << semester.start_date.year << endl;
	out_file << semester.end_date.day << " " << semester.end_date.month << " " << semester.end_date.year << endl;
	return out_file;
}

ifstream& operator >> (ifstream& in_file, Semester& semester) {
	int size;
	in_file >> size;
	in_file.ignore(1, '\n');
	for (int i = 0; i < size; i++) {
		string classname;
		getline(in_file, classname);
		semester.list_of_classes.add(classname);
	}
	in_file >> size;
	in_file.ignore(1, '\n');
	for (int i = 0; i < size; i++) {
		pair<string, string> p;
		string id, name;
		getline(in_file, id);
		getline(in_file, name);
		p = std::make_pair(id, name);
		semester.list_of_courses.add(p);
	}
	in_file >> semester.order;
	in_file >> semester.start_date.day >> semester.start_date.month >> semester.start_date.year;
	in_file >> semester.end_date.day >> semester.end_date.month >> semester.end_date.year;
	return in_file;
}
