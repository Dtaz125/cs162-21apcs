#include"Student.h"

bool operator == (const Student& student_1, const Student& student_2) {
	return student_1.studentid == student_2.studentid;
}
bool operator != (const Student& student_1, const Student& student_2) {
	return student_1.studentid != student_2.studentid;
}