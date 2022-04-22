#include"Class.h"

bool operator == (const Class& class_1, const Class& class_2) {
    return class_1.name == class_2.name;
}

bool operator != (const Class& class_1, const Class& class_2) {
    return class_1.name != class_2.name;
}

ofstream& operator << (ofstream& out_file, Class& _class) {
    out_file << std::endl;
    out_file << _class.name << std::endl;
    out_file << _class.student_list.size();
    for (int i = 0; i < _class.student_list.size(); i++) {
        out_file << _class.student_list[i]->data;
    }
    return out_file;
}

ifstream& operator >> (ifstream& in_file, Class& _class) {
    in_file.ignore(1, '\n');
    getline(in_file, _class.name);
    int size;
    in_file >> size;
    for (int i = 0; i < size; i++) {
        Student k;
        in_file >> k;
        _class.student_list.add(k);
    }
    return in_file;
}
