#include"Class.h"

bool operator == (const Class& class_1, const Class& class_2) {
    return class_1.name == class_2.name;
}

bool operator != (const Class& class_1, const Class& class_2) {
    return class_1.name != class_2.name;
}
