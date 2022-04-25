#pragma once
#include"Staff.h"
#include"other.h"
#include"Initialize.h"
void printCourseStatus(bool is_pub) {
    if (is_pub) cout << "published";
    else cout << "unpublished";
}

void changeName(int baseX, int baseY, Course& c) {
    string new_name;
    drawText(baseX, baseY, "2. Course Name: " + blank);
    drawText(baseX, baseY, "2. Course Name: ");
    cin.ignore();
    getline(cin, new_name);
    c.name = new_name;
}

void changeID(int baseX, int baseY, Course& c) {
    string new_id;
    drawText(baseX, baseY, "1. Course ID: " + blank);
    drawText(baseX, baseY, "1. Course ID: ");
    cin.ignore();
    getline(cin, new_id);
    c.id = new_id;
}

void changeTeacherName(int baseX, int baseY, Course& c) {
    string new_teacher;
    drawText(baseX, baseY, "3. Teacher Name: " + blank);
    drawText(baseX, baseY, "3. Teacher Name: ");
    cin.ignore();
    getline(cin, new_teacher);
    c.teacher_name = new_teacher;
}

void changeTeachingTime(int baseX, int baseY, Course& c) {
    string new_teacher;
    drawText(baseX, baseY, "4. Teaching Time: " + blank);
    drawText(baseX, baseY, "4. Teaching Time: ");
    cin.ignore();
    getline(cin, new_teacher);
    c.teaching_time = convert_teachingtime(new_teacher);
}

void chanegMaxStudent(int baseX, int baseY, Course& c) {
    int new_number;
    drawText(baseX, baseY, "5. Maximum Students: " + blank);
    drawText(baseX, baseY, "5. Maximum Students: ");
    cin >> new_number;
    c.max_student = new_number;
}

void changeCredits(int baseX, int baseY, Course& c) {
    int new_number;
    drawText(baseX, baseY, "6. Credits: " + blank);
    drawText(baseX, baseY, "6. Credits: ");
    cin >> new_number;
    c.credits = new_number;
}

void publishCourse(Class& HCMUS, Staff& st) {
    int baseY = 3, id;
    int curCourse = -1;
    Link link;
    Course new_c;
    do {

        system("cls");
        drawText(posCenter("MODIFY COURSE"), baseY, "---------------------");
        drawText(posCenter("MODIFY COURSE"), baseY + 1, "| MODIFY COURSE |");
        drawText(posCenter("MODIFY COURSE"), baseY + 2, "---------------------");
        //        drawText(baseX, baseY + 4, "1. School Year: "); cout << link.year;
        //        drawText(baseX, baseY + 6, "2. Semester: "); cout << link.semester;
        drawText(baseX, baseY + 4, "1. Course ID: "); cout << new_c.id;
        drawText(baseX, baseY + 6, "2. Course Name: "); cout << new_c.name;
        drawText(baseX, baseY + 8, "3. Teacher: "); cout << new_c.teacher_name;
        drawText(baseX, baseY + 10, "4. Teaching Time: "); cout << new_c.teaching_time;
        drawText(baseX, baseY + 12, "5. Maximum Students: "); cout << new_c.max_student;
        drawText(baseX, baseY + 14, "6. Credits: "); cout << new_c.credits;
        drawText(baseX, baseY + 16, "7. Publish:"); if (new_c.is_published) cout << " has been published"; else cout << " hasn't been puslished";
        drawText(baseX, baseY + 18, "8. Save and modify");
        drawText(baseX, baseY + 20, "9. Cancel");
        drawText(posCenter("Press a number: : "), baseY + 22, "Press a number: : ");

        cin >> id;

        //if (id == 1) changeYear(link, baseX, baseY + 4, "1. School Year: "); //done
        //else if (id == 2) changeSemester(link, baseX, baseY + 6, "2. Semester: "); //done
        if (id == 1) {
            changeCourseID(link, baseX, baseY + 4, "1. Course ID: "); //done
            curCourse = -1;
            travelCourse(it) {
                if (HCMUS.course_list[it].id == link.courseID) {
                    curCourse = it;
                    break;
                }
            }
            if (curCourse >= 0) new_c = HCMUS.course_list[curCourse];
        }
        else if (id == 2) { changeName(baseX, baseY + 6, new_c); }
        else if (id == 3) { changeTeacherName(baseX, baseY + 8, new_c); }
        else if (id == 4) { changeTeachingTime(baseX, baseY + 10, new_c); }
        else if (id == 5) { chanegMaxStudent(baseX, baseY + 12, new_c); }
        else if (id == 6) { changeCredits(baseX, baseY + 14, new_c); }
        else if (id == 7){
           new_c.is_published ^= 1;
        }
        else if (id == 8){
           if (curCourse >= 0) HCMUS.course_list[curCourse] = new_c;
           outputCourseData(HCMUS);
        }
        system("cls");
    } while (id != 9);
}
