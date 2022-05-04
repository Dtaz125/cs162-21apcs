#pragma once
#include"courseData.h"
#include"createNewCourse.h"
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
void readSchedule(string _inputfile) {
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
	Class tmp;
	inputCourseData(tmp);
	for (int i = 0; i < content.size(); i++) {
		for (int j = 0; j < tmp.numcourse; j++) {
			if (content[i][0] == tmp.course_list[j].id) {
				tmp.course_list[j].teaching_time = convert_teachingtime(content[i][1]);
				break;
			}
		}
	}
	outputCourseData(tmp);
	file.close();
}

void writeSchedule(string _outputfile) {
	ofstream file;
	file.open(_outputfile);
	file << "Course Name" << "," << "ID" << "," << "Schedule" << '\n';
	Class tmp;
	inputCourseData(tmp);
	for (int i = 0; i < tmp.numcourse; i++) {
		file << tmp.course_list[i].name << "," << tmp.course_list[i].id << "," << tmp.course_list[i].teaching_time << '\n';
	}
	file.close();
}