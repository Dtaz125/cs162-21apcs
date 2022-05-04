#include"SchoolYear.h"

bool operator == (const SchoolYear& first, const SchoolYear& second) {
	return first.name == second.name;
}
bool operator != (const SchoolYear& first, const SchoolYear& second) {
	return first.name != second.name;
}

ofstream& operator << (ofstream& out_file, SchoolYear& schooyear) {
	out_file << schooyear.name;
	return out_file;
}

ifstream& operator >> (ifstream& in_file, SchoolYear& schooyear) {
	in_file >> schooyear.name;
	return in_file;
}
