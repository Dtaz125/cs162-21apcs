#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include"User.h"
class Account {
private:
	string username;
	string password;
	User user_info;
public:
	Account();
	Account(string useracc, string pass, const User& info);
	const string& getUsername();
	const string& getPassword();
	const User& getInfo();
	void setUsername(string useracc);
	void setPassword(string pass);
	void setInfo(const User& info);
};
#endif // !ACCOUNT_H
