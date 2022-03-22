
#ifndef STAFF_H
#define STAFF_H

#include"Account.h"

class Staff : public Account {
private:

public:
	Staff();
	Staff(string useracc, string pass, const User& info);
	Staff(const Staff& staff);
};
#endif // !STAFF_H