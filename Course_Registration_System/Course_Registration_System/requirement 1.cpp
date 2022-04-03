#include<iostream>
#include<SchoolYear.h>
#include<Class.h>
#include<Student.h>
#include<fstream>
#include<sstream>
#include <vector>
using namespace std;

int convertStringToInt(string _string) {
	int x;
	stringstream temp(_string);
	temp >> x;

	return x;
}

void inputToVector(string _inputfile) {
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
	else
		cout << "Could not open the file." << endl;

	for (int i = 0; i < content.size(); i++) {							//basically i read csv file into 2D vector.
		for (int j = 0; j < content[i].size(); j++) {					//this code is for displaying all the information stored
			cout << content[i][j] << " ";								//a loop in a loop
		}																//note: this is only for demonstrating purposes and will not be included in the final commit		
		cout << endl;
	}

	for (int i = 0; i < content.size(); i++) {							//first loop,
		//add new student												//now, how do i add new student using linked list,
																		//then i could input the data in, using loop for every student
																		//bool add(const T& new_data) or void add(const Linked_List<T>& new_list)

		//Student(content[i][0], content[i][1], content[i][2], content[i][3], content[i][3]);	
	}																	

}


int main() {
	string year2021 = "year2021-2022";			//create schooyear
	SchoolYear schoolyear2022(year2021);

	string class20apcs1string = "20APCS1";			//create class
	string class20apcs2string = "20APCS2";
	string class20clc1string = "20CLC1";
	string class20clc11string = "20CLC11";
	string class20vpstring = "20VP";
	Class class20apcs1(class20apcs1string,40);			//meaning 40 members in this class
	Class class20apcs2(class20apcs2string, 40);
	Class class20clc1(class20clc1string, 40);
	Class class20clc11(class20clc11string, 40);
	Class class20vp(class20vpstring, 40);

	inputToVector("class20apcs1 student information.csv");


}
