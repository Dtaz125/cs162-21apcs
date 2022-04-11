#include"SchoolYear.h"

bool operator == (const SchoolYear& first, const SchoolYear& second) {
	return first.name == second.name;
}
bool operator != (const SchoolYear& first, const SchoolYear& second) {
	return first.name != second.name;
}