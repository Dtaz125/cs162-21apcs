#include"Staff.h"

Staff::Staff() {
	//empty
}
Staff::Staff(string useracc, string pass, const User& info): username(useracc), password(pass), user_info(info){
	//empty
}
Staff::Staff(const Staff& staff) : username(staff.username), password(staff.password), user_info(staff.user_info) {
	//empty
}
const string& Staff::getUsername() {
	return username;
}
const string& Staff::getPassword() {
	return password;
}
const User& Staff::getInfo() {
	return user_info;
}
void Staff::setUsername(string useracc) {
	username = useracc;
}
void Staff::setPassword(string pass) {
	password = pass;
}
void Staff::setInfo(const User& info) {
	user_info = info;
}
bool operator == (const Staff& first, const Staff& second) {
	return first.user_info.social_id == second.user_info.social_id;
}

bool operator != (const Staff& first, const Staff& second) {
	return first.user_info.social_id != second.user_info.social_id;
}

