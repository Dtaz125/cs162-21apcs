#pragma once
#include"courseData.h"
float calculateGPA(Student& st, float& count) {
    if (st.id == "") return 0.0;
    float sum = 0.0;
    count = 0.0;
    Class tmp;
    inputCourseData(tmp);
    for (int i = 0; i < st.numcourse; i++) {
        string id = st.list_of_courses[i].first;
        int index = tmp.getCourse(id);
        cout << index << endl;
        if (index != -1) {
            for (int j = 0; j < tmp.course_list[index].student_score.size(); j++) {
                if (st.id == tmp.course_list[index].student_score[j]->data.id) {
                    sum += tmp.course_list[index].student_score[j]->data.total_mark * (float)tmp.course_list[index].credits;
                    count += (float)tmp.course_list[index].credits;
                    break;
                }
            }
        }
    }
    if (count == 0.0) return 0.0;
    return sum / count;
}
