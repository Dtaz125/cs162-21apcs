#pragma once
#include"Course.h"
#include"Initialize.h"
#include"other.h"


void displayScoreinCourse(string id_course) {
    Class curr;
    int id, baseX = 5, baseY = 1, index=-1;
    inputCourseData(curr);
    system("cls");
    do {
        drawText(posCenter("COURSE SCOREBOARD"), baseY, "---------------------");
        drawText(posCenter("COURSE SCOREBOARD"), baseY + 1, "| COURSE SCOREBOARD |");
        drawText(posCenter("COURSE SCOREBOARD"), baseY + 2, "---------------------");
        baseY += 8;
        drawText(baseX, baseY, "No");
        drawText(baseX + 8, baseY, "ID"); 
        drawText(baseX + 23, baseY, "Full Name"); 
        drawText(baseX + 35, baseY, "Total"); 
        drawText(baseX + 50, baseY, "Final");
        drawText(baseX + 63, baseY, "Midterm"); 
        drawText(baseX + 76, baseY, "Others");
        int d = 0;
        for (int i = 0; i < curr.numcourse; i++) {
            if (curr.course_list[i].id == id_course) {
                index = i; break;
            }
        }
        if (index != -1) {
            for (int i = 0; i < curr.course_list[index].student_score.size(); i++) {
                Node<Score>* s = curr.course_list[index].student_score[i];
                baseY += 1;
                d++;
                drawText(baseX, baseY, to_string(d));
                drawText(baseX + 8, baseY, ""); cout << s->data.id;
                drawText(baseX + 23, baseY, ""); cout << s->data.fullname;
                drawText(baseX + 35, baseY, ""); cout << s->data.total_mark;
                drawText(baseX + 50, baseY, ""); cout << s->data.final_mark;
                drawText(baseX + 63, baseY, ""); cout << s->data.midterm_mark;
                drawText(baseX + 76, baseY, "");
                for (int j = 0; j < s->data.number_of_other_score; j++) {
                    cout << s->data.other_score[j] << " ";
                }
            }
            drawText(baseX + 76, baseY+3, "Press 1 to exit: ");
            cin >> id;
        }
    } while (id != 1);
    system("cls");
}