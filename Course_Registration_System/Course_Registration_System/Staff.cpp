#include"Staff.h"
#include"Student.h"
#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>
using std::vector;
using std::getline;
using std::stringstream;

void readCSV(Node<SchoolYear>*& new_year, Class*& classname, const string& _inputfile) {
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

	for (int i = 0; i < content.size(); i++) {							//loops for every line
		Student new_stu;
		new_stu.no = content[i][0];
		new_stu.studentid = content[i][1];

		User new_user;													//the user_info member in Account class is private. so i have to create a new temp User varible
		new_user.firstname = content[i][2];								//then use the setuser function in Account to set the information
		new_user.lastname = content[i][3];
		if (content[i][4] == "M") {										//0 if male. 1 if female
			new_user.gender = 0;
		}
		else new_user.gender = 1;
		new_user.birth.day = stoi(content[i][5]);
		new_user.birth.month = stoi(content[i][6]);
		new_user.birth.year = stoi(content[i][7]);

		new_stu.user_info = new_user;
		new_stu.student_class = classname;

		new_year->data.list_of_semesters[new_year->data.list_of_semesters.size() - 1]->data.list_of_classes.contains(*classname)->data.student_list.add(new_stu);
	}
}

void writeCSV(Node<Course>*& _course, const string& _outputfile) {
	fstream file;
	file.open(_outputfile, ios::out);

	if (file.is_open()) {
		file << _course->data.student_list.no << ",";
		file << _course->data.student_list.studentid << ",";
		file << _course->data.student_list.user_info.firstname << ",";
		file << _course->data.student_list.user_info.lastname << ",";
		if (_course->data.student_list.user_info.lastname == "0") {										//M if male. F if female
			file << "M,";
		}
		else file << "F,";
		file << _course->data.student_list.user_info.birth.day << ",";
		file << _course->data.student_list.user_info.birth.month << ",";
		file << _course->data.student_list.user_info.birth.year << ",\n";

		//i couldnt try to run the code due to other errors in the project
		//i need ideas to get to next node of students
	}
}

bool operator == (const Staff& first, const Staff& second) {
	return first.user_info.social_id == second.user_info.social_id;
}

bool operator != (const Staff& first, const Staff& second) {
	return first.user_info.social_id != second.user_info.social_id;
}

