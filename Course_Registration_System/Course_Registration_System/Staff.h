#pragma once
#ifndef STAFF_H
#define STAFF_H

#include"Account.h"

class Staff : public Account {
private:

public:
	Staff() : Account() {}
	Staff(string useracc, string pass, const User& info) : Account(useracc, pass, info) {}

};
#endif // !STAFF_H