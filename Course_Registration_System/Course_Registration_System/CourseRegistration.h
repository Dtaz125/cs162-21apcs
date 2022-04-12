#pragma once
#include<string>
#include"Date.h"
struct CourseRegistration {
	std::string name = "";
	Date start_date = { 0,0,0 };
	Date end_date = { 0,0,0 };
};
