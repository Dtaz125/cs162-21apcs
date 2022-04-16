#pragma once
struct Link {
    string year = "";
    int semester = 0;
    string courseID = "";
    string link = "";
    string classname = "";
};

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
