// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char* str) {
    int count = 0;
    bool inWord = false;
    bool hasDigit = false;
    while (*str) {
        if (*str != ' ' && inWord == false) {
            hasDigit = false;
            if (isdigit(*str)) hasDigit = true;
            inWord = true;
        } else if (inWord == true && isdigit(*str)) {
            hasDigit = true;
        } else if (*str == ' ' && inWord == true) {
            inWord = false;
            if (!hasDigit) count++;
        }
        str++;
    }
    return count;
}

unsigned int faStr2(const char* str) {
    int count = 0;
    bool inWord = false;
    bool rightFormat = true;
    while (*str) {
        if (*str != ' ' && inWord == false) {
            rightFormat = false;
            if (isupper(*str)) rightFormat = true;
            inWord = true;
        } else if (inWord == true && *str != ' ' && !islower(*str)) {
            rightFormat = false;
        } else if (*str == ' ' && inWord == true) {
            inWord = false;
            if (rightFormat) count++;
        }
        str++;
    }
    return count;
}

unsigned int faStr3(const char* str) {
    int count = 0;
    double sum = 0;
    bool inWord = false;
    while (*str) {
        if (*str != ' ' && inWord == false) {
            count++;
            sum++;
            inWord = true;
        } else if (*str != ' ' && inWord == true) {
            sum++;
        } else if (*str == ' ' && inWord == true) {
            inWord = false;
        }
        str++;
    }
    return round(sum/count);
}
