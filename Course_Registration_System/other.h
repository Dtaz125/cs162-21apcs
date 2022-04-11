#pragma once
#include <iostream>
#include "Date.h"
using namespace std;

bool isdigit(char ch){
    return '0' <= ch && ch <= '9';
}

bool validDate(string birth, Date &dt){
    for (int i = 0; i < birth.size(); i++){
        char ch = birth[i];
        if (!isdigit(ch) && ch != ' ' && ch != '/')
            return false;
        if (ch == ' ' || ch == '/'){
            if (i == 0 || i == birth.size() - 1) return false;
            if (!isdigit(birth[i - 1]) || !isdigit(birth[i + 1])) return false;
        }
    }
    int iter = 0;
    dt.day = dt.month = dt.year = 0;
    while (iter < birth.size() && dt.day <= 31){
        if (isdigit(birth[iter])){
            dt.day = dt.day * 10 + birth[iter++] - '0';
            if (dt.day >= 100){
                dt.day /= 10;
                iter--;
                break;
            }
        }
        else {
            iter++;
            break;
        }
    }
    while (iter < birth.size() && dt.month <= 12){
        if (isdigit(birth[iter])){
            dt.month = dt.month * 10 + birth[iter++] - '0';
            if (dt.month >= 100){
                dt.month /= 10;
                iter--;
                break;
            }
        }
        else{
            iter++;
            break;
        }
    }
    while (iter < birth.size()){
        if (isdigit(birth[iter]))
            dt.year = dt.year * 10 + birth[iter++] - '0';
        else{
            iter++;
            break;
        }
    }
    if (dt.day > 31 || dt.month > 12 || dt.day == 0 || dt.month == 0) return false;
    return true;
}

