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
	Account() { }
	Account(string useracc, string pass, const User& info) : username(useracc), password(pass), user_info(info) {}
	inline const string& getUsername() { return username; }
	inline const string& getPassword() { return password; }
	inline const User& getInfo() { return user_info; }
	inline void setUsername(string useracc) { username = useracc; }
	inline void setPassword(string pass) { password = pass; }
	inline void setInfo(const User& info) { user_info = info; }
};
#endif ACCOUNT_H