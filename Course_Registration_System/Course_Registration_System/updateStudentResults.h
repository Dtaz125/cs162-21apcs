#pragma once
#include"Staff.h"
#include"Initialize.h"
#include"other.h"
#include"Link.h"
#include"scheduleCSV.h"
void updateStudentResults(const Staff& st) {
    system("cls");
    int id, baseY=3;
    Link link;
    do {
        drawText(posCenter("UPDATE RESULTS"), baseY, "------------------");
        drawText(posCenter("UPDATE RESULTS"), baseY + 1, "| UPDATE RESULTS |");
        drawText(posCenter("UPDATE RESULTS"), baseY + 2, "------------------");
        drawText(baseX, baseY + 3, "1. Course ID: "); cout << link.courseID;
        drawText(baseX, baseY + 5, "2. Link CSV: "); cout << link.link;
        drawText(baseX, baseY + 7, "3. Update");
        drawText(baseX, baseY + 9, "4. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 11, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeCourseID(link, baseX, baseY + 3, "1. Course ID: "); }
        else if (id == 2) { changeLinkCSV(link, baseX, baseY + 5, "2. Link CSV: "); }
        else if (id == 3) { 
            Class tmp;
            inputCourseData(tmp);
            int index = tmp.getCourse(link.courseID);
            if (index != -1) {
                readCSV_Scoreboard(tmp.course_list[index], link.link);
            }
            outputCourseData(tmp);
            drawText(baseX, baseY + 7, "Update Completed!");
        }
        system("cls");
    } while (id != 4);
    system("cls");
}

void writeScoretoCSV(Staff& st) {
    system("cls");
    int id, baseY = 3;
    Link link;
    do {
        drawText(posCenter("CSV RESULTS"), baseY, "---------------");
        drawText(posCenter("CSV RESULTS"), baseY + 1, "| CSV RESULTS |");
        drawText(posCenter("CSV RESULTS"), baseY + 2, "---------------");
        drawText(baseX, baseY + 3, "1. Course ID: "); cout << link.courseID;
        drawText(baseX, baseY + 5, "2. Location: "); cout << link.link;
        drawText(baseX, baseY + 7, "3. Process Now");
        drawText(baseX, baseY + 9, "4. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 11, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeCourseID(link, baseX, baseY + 3, "1. Course ID: "); }
        else if (id == 2) { changeLinkCSV(link, baseX, baseY + 5, "2. Location: "); }
        else if (id == 3) {
            Class tmp;
            inputCourseData(tmp);
            int index = tmp.getCourse(link.courseID);
            if (index != -1) {
                writeCSV_Scoreboard(tmp.course_list[index], link.link);
            }
            drawText(baseX, baseY + 7, "Update Completed!");
        }
        system("cls");
    } while (id != 4);
    system("cls");
}


void writeCoursetoCSV(Staff& st) {
    system("cls");
    int id, baseY = 3;
    Link link;
    do {
        drawText(posCenter("CSV RESULTS"), baseY, "---------------");
        drawText(posCenter("CSV RESULTS"), baseY + 1, "| CSV RESULTS |");
        drawText(posCenter("CSV RESULTS"), baseY + 2, "---------------");
        drawText(baseX, baseY + 3, "1. Course ID: "); cout << link.courseID;
        drawText(baseX, baseY + 5, "2. Location: "); cout << link.link;
        drawText(baseX, baseY + 7, "3. Process Now");
        drawText(baseX, baseY + 9, "4. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 11, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeCourseID(link, baseX, baseY + 3, "1. Course ID: "); }
        else if (id == 2) { changeLinkCSV(link, baseX, baseY + 5, "2. Location: "); }
        else if (id == 3) {
            Class tmp;
            inputCourseData(tmp);
            int index = tmp.getCourse(link.courseID);
            if (index != -1) {
                writeCSV(tmp.course_list[index], link.link);
                drawText(baseX, baseY + 7, "Update Completed!");
            }
        }
        system("cls");
    } while (id != 4);
    system("cls");
}

void importScheduleCSV(Staff& st) {
    system("cls");
    int id, baseY = 3;
    Link link;
    do {
        drawText(posCenter("IMPORT SCHEDULE"), baseY, "-------------------");
        drawText(posCenter("IMPORT SCHEDULE"), baseY + 1, "| IMPORT SCHEDULE |");
        drawText(posCenter("IMPORT SCHEDULE"), baseY + 2, "-------------------");
        drawText(baseX, baseY + 3, "1. File Location: "); cout << link.link;
        drawText(baseX, baseY + 5, "2. Process Now");
        drawText(baseX, baseY + 7, "3. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 9, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeLinkCSV(link, baseX, baseY + 3, "1. File Location: "); }
        else if (id == 2) { 
            readSchedule(link.link);
            drawText(baseX, baseY + 5, "Update Completed!");
        }
        system("cls");
    } while (id != 3);
    system("cls");
}

void exportScheduleCSV(Staff& st) {
    system("cls");
    int id, baseY = 3;
    Link link;
    do {
        drawText(posCenter("EXPORT SCHEDULE"), baseY, "-------------------");
        drawText(posCenter("EXPORT SCHEDULE"), baseY + 1, "| EXPORT SCHEDULE |");
        drawText(posCenter("EXPORT SCHEDULE"), baseY + 2, "-------------------");
        drawText(baseX, baseY + 3, "1. File Location: "); cout << link.link;
        drawText(baseX, baseY + 5, "2. Process Now");
        drawText(baseX, baseY + 7, "3. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 9, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { changeLinkCSV(link, baseX, baseY + 3, "1. File Location: "); }
        else if (id == 2) {
            writeSchedule(link.link);
            drawText(baseX, baseY + 5, "Update Completed!");
        }
        system("cls");
    } while (id != 3);
    system("cls");
}

void schedulewithCSV(Staff& st) {
    system("cls");
    int id, baseY = 3;
    Link link;
    do {
        drawText(posCenter("SCHEDULE"), baseY, "------------");
        drawText(posCenter("SCHEDULE"), baseY + 1, "| SCHEDULE |");
        drawText(posCenter("SCHEDULE"), baseY + 2, "------------");
        drawText(baseX, baseY + 3, "1. Import Schedule From CSV");
        drawText(baseX, baseY + 5, "2. Export Schedule To CSV");
        drawText(baseX, baseY + 7, "3. Exit");
        drawText(posCenter("Press a number to change/view information: "), baseY + 9, "Press a number to change/view information: ");
        cin >> id;
        if (id == 1) { importScheduleCSV(st); }
        else if (id == 2) { exportScheduleCSV(st); }
        system("cls");
    } while (id != 3);
    system("cls");
}
void workonScoreboard(Staff& st) {
    system("cls");
    int id, baseY = 3;
    Link link;
    do {
        drawText(posCenter("CSV WORKING"), baseY, "---------------");
        drawText(posCenter("CSV WORKING"), baseY + 1, "| CSV WORKING |");
        drawText(posCenter("CSV WORKING"), baseY + 2, "---------------");
        drawText(baseX, baseY + 3, "1. Update Scoreboard from CSV");
        drawText(baseX, baseY + 5, "2. Course Schedule with CSV");
        drawText(baseX, baseY + 7, "3. Write Scoreboard to CSV");
        drawText(baseX, baseY + 9, "4. Write Course Information to CSV");
        drawText(baseX, baseY + 11, "5. Exit");
        drawText(posCenter("Your Choice: "), baseY + 13, "Your Choice: ");
        cin >> id;
        
        if (id == 1) { updateStudentResults(st); }
        else if (id == 2) { schedulewithCSV(st); }
        else if (id == 3) { writeScoretoCSV(st); }
        else if (id == 4) { writeCoursetoCSV(st); }
        system("cls");
    } while (id != 5);
    system("cls");
}
