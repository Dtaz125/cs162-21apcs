#include"Semester.h"
bool operator == (const Semester& first, const Semester& second) {
    return first.order == second.order;
}

bool operator != (const Semester& first, const Semester& second) {
    return first.order != second.order;
}
