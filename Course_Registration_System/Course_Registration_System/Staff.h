
#ifndef STAFF_H
#define STAFF_H
#include"Account.h"
class Staff {
private:
	string username;
	string password;
	User user_info;
public:
	Staff();
	Staff(string useracc, string pass, const User& info);
	Staff(const Staff& staff);
	const string& getUsername();
	const string& getPassword();
	const User& getInfo();
	void setUsername(string useracc);
	void setPassword(string pass);
	void setInfo(const User& info);
	friend bool operator == (const Staff& first, const Staff& second);
	friend bool operator != (const Staff& first, const Staff& second);
};
#endif // !STAFF_H