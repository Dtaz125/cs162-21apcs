#include"Staff.h"
#include"Student.h"
#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>
using std::vector;
using std::getline;
using std::stringstream;
using std::stoi;
void readCSV(Class& classname, string _inputfile) {
	string inputFile = _inputfile;

	vector<vector<string>> content;
	vector<string> row;
	string line, word;

	fstream file(inputFile, ios::in);
	if (file.is_open()) {
		while (getline(file, line)) {
			row.clear();

			stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}

	for (int i = 0; i < content.size(); i++) {
		Student new_stu;
		new_stu.no = content[i][0];
		new_stu.studentid = content[i][1];
		User new_user;
		new_user.firstname = content[i][2];
		new_user.lastname = content[i][3];
		if (content[i][4] == "M") {
			new_user.gender = 0;
		}
		else new_user.gender = 1;
		new_user.birth.day = stoi(content[i][5]);
		new_user.birth.month = stoi(content[i][6]);
		new_user.birth.year = stoi(content[i][7]);

		new_stu.user_info = new_user;
		new_stu.student_class = content[i][8];							// we will input class as string using csv file

		classname.student_list.add(new_stu);							//add new_stu to this class as linkedlist of students
	}
}

void writeCSV(Course& _course, const string& _outputfile) {
	fstream file;
	file.open(_outputfile, ios::out);
	for (Iterator<Score> iter = _course.student_score.begin(); iter != _course.student_score.end(); iter++) {
		Score g = *iter;
		file << g.no<< "," << g.id <<","<<g.fullname<<"\n";
	}
}

bool operator == (const Staff& first, const Staff& second) {
	return first.user_info.social_id == second.user_info.social_id;
}

bool operator != (const Staff& first, const Staff& second) {
	return first.user_info.social_id != second.user_info.social_id;
}

