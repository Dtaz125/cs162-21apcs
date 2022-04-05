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

void inputToVector(Class *classname, string _inputfile) {
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


	for (int i = 0; i < content.size(); i++) {							//loops for every line
		Student new_stu;
		new_stu.setNO(content[i][0]);
		new_stu.setID(content[i][1]);

		User new_user;													//the user_info member in Account class is private. so i have to create a new temp User varible
		new_user.firstname = content[i][2];								//then use the setuser function in Account to set the information
		new_user.lastname = content[i][3];
		if (content[i][4] == "M") {										//0 if male. 1 if female
			new_user.gender = 0;
		}
		else new_user.gender = 1;
		new_user.birth.day = convertStringToInt(content[i][5]);			//this is where convert to string function is needed. because day month year members are all int datatype
		new_user.birth.month = convertStringToInt(content[i][6]);
		new_user.birth.year = convertStringToInt(content[i][7]);

		new_stu.setInfo(new_user);
		new_stu.setClass(classname);									//this should set the class of this new student

		// now how do i add a new student in a linked list: list.add(new_stu)?
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
	Class class20apcs1(class20apcs1string, 4);			//meaning 4 members in this class
	Class class20apcs2(class20apcs2string, 4);
	Class class20clc1(class20clc1string, 4);
	Class class20clc11(class20clc11string, 4);
	Class class20vp(class20vpstring, 4);
	
	Class* class20apcs1Pointer = &class20clc11;				//i have to create a pointer, in order to use the function void setClass(Class* _class) in Student Class
	inputToVector(class20apcs1Pointer, "class20apcs1 student information.csv");


}
