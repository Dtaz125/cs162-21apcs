#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<string>
using namespace std;

struct Staff {
    void function1();
    void function2();
};

Staff::function1() {

}

Staff::function2() {

}

class Student {
private:
    string studentID;
    string No;
    Class class;

    void list_of_courses();
    void setStudent();
    string getID();
    string getName();
    string getTeacherName();
    int getMaxStudent();
    Time getTeachingTime();
    int getCredits();
};


void Student::list_of_courses() {

}

void Student::setStudent() {

}

string Student::getID() {

}

string Student::getName() {

}

string Student::getTeacherName() {

}

int Student::getMaxStudent() {

}

Time Student::getTeachingTime() {

}

int Student::getCredits() {

}

class Account {
private:
    string username;
    char[] password;
    User user_info;
public:
    void setAccount();
    string getFirstName();
    string getLastName();
    bool getGender();
    string getSocial_ID();
    string getBirth();
};

void Account::setAccount() {

}

string Account::getFirstName() {

}
string Account::getLastName() {

}
bool Account::getGender() {

}
string Account::getSocial_ID() {

}
string Account::getBirth() {

}

struct User {
    string firstName;
    string lastName;
    bool gender;
    string social_ID;
    string Birth;
};


void insert(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    return;
}

#endif
