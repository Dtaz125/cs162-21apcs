#pragma once
struct Link {
    string year = "";
    int semester = 0;
    string courseID = "";
    string studentID = "";
    string link = "";
    string classname = "";
    string classname_1 = "";
};

void changeStudentID(Link& link, int baseX, int baseY, string text) {
    string new_link;
    drawText(baseX, baseY, text + blank);
    drawText(baseX, baseY, text);
    cin.ignore();
    getline(cin, new_link);
    link.studentID = new_link;
}

void changeYear(Link& link, int baseX, int baseY, string text) {
    string new_link;
    drawText(baseX, baseY, text + blank);
    drawText(baseX, baseY, text);
    cin.ignore();
    getline(cin, new_link);
    link.year = new_link;
}

void changeSemester(Link& link, int baseX, int baseY, string text) {
    int new_link;
    drawText(baseX, baseY, text + blank);
    drawText(baseX, baseY, text);
    cin.ignore();
    cin >> new_link;
    link.semester = new_link;
}

void changeCourseID(Link& link, int baseX, int baseY, string text) {
    string new_link;
    drawText(baseX, baseY, text + blank);
    drawText(baseX, baseY, text);
    cin.ignore();
    getline(cin, new_link);
    link.courseID = new_link;
}

void changeLinkCSV(Link& link, int baseX, int baseY, string text) {
    string new_link;
    drawText(baseX, baseY, text + blank);
    drawText(baseX, baseY, text);
    cin.ignore();
    getline(cin, new_link);
    link.link = new_link;
}

void changeClass(Link& link, int baseX, int baseY, string text) {
    string new_link;
    drawText(baseX, baseY, text + blank);
    drawText(baseX, baseY, text);
    cin.ignore();
    getline(cin, new_link);
    link.classname = new_link;
}

void changeClass_1(Link& link, int baseX, int baseY, string text) {
    string new_link;
    drawText(baseX, baseY, text + blank);
    drawText(baseX, baseY, text);
    cin.ignore();
    getline(cin, new_link);
    link.classname_1 = new_link;
}
