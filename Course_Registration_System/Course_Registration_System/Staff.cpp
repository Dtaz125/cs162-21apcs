#include"Staff.h"

Staff::Staff() : Account() {
	//empty
}
Staff::Staff(string useracc, string pass, const User& info) : Account(useracc, pass, info) {
	//empty
}
Staff::Staff(const Staff& staff) {
	Account::Account(staff);
}

