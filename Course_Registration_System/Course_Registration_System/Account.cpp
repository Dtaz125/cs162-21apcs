#include"Account.h"
#include"Student.h"
Account::Account() {
	
}
Account::Account(string useracc, string pass, const User& info) : username(useracc), password(pass), user_info(info) {
	
}
Account::Account(const Account& account): username(account.username), password(account.password), user_info(account.user_info) {
	
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