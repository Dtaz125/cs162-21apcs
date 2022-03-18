#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<string>
using namespace std;

class student {
protected:
    int studentID = 0;
    string studentName;
public:
    virtual void setVariables();
    virtual void printData();
};

void student::setVariables() {
    do {
        cout << "Student ID: ";
        cin >> studentID;
    } while (studentID <= 0);
    cout << "Name of the student: ";
    cin.ignore(1);
    getline(cin, studentName);
}

void student::printData() {
    cout << "Student ID: " << studentID << endl;
}


class CTTT : public student {
private:
    string whichClass;
public:
    void setVariables();
    void printData();
};

void CTTT::setVariables() {
    student::setVariables();
    cout << "Which CNTT class is this ?" << endl;
    cin >> whichClass;
}

void CTTT::printData() {
    student::printData();
}


class CLC : public student {
private:
    string whichClass;
public:
    void setVariables();
    void printData();
};

void CLC::setVariables() {
    student::setVariables();
    cout << "Which CLC class is this ?" << endl;
    cin >> whichClass;

}

void CLC::printData() {
    student::printData();
}


class VP : public student {
private:
    string whichClass;
public:
    void setVariables();
    void printData();
};

void VP::setVariables() {
    student::setVariables();
    cout << "Which VP class is this ?" << endl;
    cin >> whichClass;
}

void VP::printData() {
    student::printData();
}


class schoolYear {
private:
    int classType = 0, studentCounter = 0, totalStudent = 0, CNTTcounter = 0, CLCCounter = 0, VPcounter = 0;
    student* student[100];
public:
    void yearlyInput();
    void printOut();
};

void schoolYear::yearlyInput() {

    cout << "Enter # of products you want to process:  ";
    cin >> totalStudent;


    while (studentCounter < totalStudent) {
        cout << "Is this student " << studentCounter + 1 << " from CNTT, CLC or VP? (enter 1 for CNTT / 2 for CLC / 3 for VP): ";
        cin >> classType;

        if (classType == 1) {
            student[studentCounter] = new CTTT();
            student[studentCounter]->setVariables();
            cout << endl << endl;
            studentCounter++;
            CNTTcounter++;
        }
        else if (classType == 2){
            student[studentCounter] = new CLC();
            student[studentCounter]->setVariables();
            cout << endl << endl;
            studentCounter++;
            CLCCounter++;
        }
        else {
            student[studentCounter] = new VP();
            student[studentCounter]->setVariables();
            cout << endl << endl;
            studentCounter++;
            VPcounter++;
        }
    }
}

void schoolYear::printOut() {
    for (int i = 0; i < totalStudent; ++i) {
        student[i]->printData();
        cout << endl;
    }
    cout << endl << endl;
}


#endif