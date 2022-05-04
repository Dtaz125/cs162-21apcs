#include"Semester.h"
bool operator == (const Semester& first, const Semester& second) {
    return first.order == second.order;
}

bool operator != (const Semester& first, const Semester& second) {
    return first.order != second.order;
}

ofstream& operator << (ofstream& out_file, Semester& semester) {
	out_file << semester.order << endl;
	out_file << semester.start_date.day << " " << semester.start_date.month << " " << semester.start_date.year << endl;
	out_file << semester.end_date.day << " " << semester.end_date.month << " " << semester.end_date.year << endl;
	for (Iterator<pair<string, string>> iter = semester.list_of_courses.begin(); iter != semester.list_of_courses.end(); iter++) {
		pair<string, string> p = *iter;
		if (p.first == "\n" || p.second == "\n") continue;
		if (p.first == "" || p.second == "") continue;
		out_file << p.first << endl << p.second << endl;
	}
	return out_file;
}

ifstream& operator >> (ifstream& in_file, Semester& semester) {
    in_file >> semester.order;
	in_file >> semester.start_date.day >> semester.start_date.month >> semester.start_date.year;
	in_file >> semester.end_date.day >> semester.end_date.month >> semester.end_date.year;
    in_file.ignore();
    while (!in_file.eof()){
		pair<string, string> p;
		string id, name;
		getline(in_file, id);
		getline(in_file, name);
		p = std::make_pair(id, name);
		if (p.first == "\n" || p.second == "\n") continue;
		if (p.first == "" || p.second == "") continue;
		semester.list_of_courses.add(p);
	}
	return in_file;
}
