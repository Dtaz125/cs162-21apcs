#pragma once
#ifndef USER_H
#define USER_H
#include<string>
#include"Date.h"
using std::string;

struct User {
	string firstname;
	string lastname;
	bool gender;
	string social_id;
	Date birth;
};

#endif // !USER_H
