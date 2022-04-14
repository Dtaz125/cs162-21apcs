#include"Course.h"

bool operator == (const Course& course_1, const Course& course_2) {
    return course_1.id == course_2.id;
}
bool operator != (const Course& course_1, const Course& course_2) {
    return course_1.id != course_2.id;
}
bool operator == (const Score& score_1, const Score& score_2) {
    return score_1.id == score_2.id;
}

bool operator != (const Score& score_1, const Score& score_2) {
    return score_1.id != score_2.id;
}