#include "MainGUI.h"
#include "Initialize.h"
#include "Login.h"
#include "other.h"
#include "getData.h"
#include "testDatafile.h"
#include"CourseRegistrationData.h"
#include"calculateGPA.h"
#define travel(it, var) for(auto it = var.begin(); it != var.end(); it++)
using namespace std;

int main()
{
    Class HCMUS = {"HCMUS"};
    inputAllData(HCMUS);
    system("Color 9F");
    InitializeConsole();
    bool isStudent = false;
    drawText(posCenter("COURSE REGISTRATION SYSTEM(Staff/Student)[0/1]: "), 10, "COURSE REGISTRATION SYSTEM(Staff/Student)[0/1]: ");
    cin >> isStudent;
    Student stu;
    Staff sta;
    if (isStudent) {
        login(HCMUS, stu);
        drawMainGUI(HCMUS, stu, 1);
    }
    else {
        login(HCMUS, sta);
        drawMainGUI(HCMUS, sta, 0);
    }
	/*Class tmp;
	readCSV_1(tmp, "test_csv.csv");
	for (int i = 0; i < tmp.student_list.size(); i++) {
		Node<Student>* k = tmp.student_list[i];
		cout << k->data.username << " " << k->data.password << " " << k->data.id << " " << k->data.user_info.firstname << " " << k->data.user_info.lastname << endl;
	}*/
    return 0;
}
