#include"Account.h"
#include"Student.h"
Account::Account() {
	username = "admin";				//this constructor is for a default account, the account information is left as blanked
	password = "admin";				//username and password is admin/admin
}
Account::Account(string useracc, string pass, const User& info) : username(useracc), password(pass), user_info(info) {
	user_info.firstname = info.firstname;			//struct User
	user_info.lastname = info.lastname;
	user_info.gender = info.gender;
	user_info.social_id = info.social_id;

	user_info.birth.day = info.birth.day;			//struct Date
	user_info.birth.month = info.birth.month;
	user_info.birth.year = info.birth.year;
}
Account::Account(const Account& account): username(account.username), password(account.password), user_info(account.user_info) {
	user_info.firstname = account.user_info.firstname;			//struct User
	user_info.lastname = account.user_info.lastname;
	user_info.gender = account.user_info.gender;
	user_info.social_id = account.user_info.social_id;
	
	user_info.birth.day = account.user_info.birth.day;			//struct Date
	user_info.birth.month = account.user_info.birth.month;
	user_info.birth.year = account.user_info.birth.year;
}
const string& Account::getUsername() { 
	return username;
}
const string& Account::getPassword() { 
	return password;
}
const User& Account::getInfo() { 
	return user_info;
}
void Account::setUsername(string useracc) { 
	username = useracc;
}
void Account::setPassword(string pass) { 
	password = pass; 
}
void Account::setInfo(const User& info) { 
	user_info = info;
}