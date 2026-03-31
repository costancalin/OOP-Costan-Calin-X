#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

char* IntToStack(int value, int base) {
    static char buffer[65];
    int i = 0;
    if (value == 0) return (char*)"0";
    unsigned int temp = (unsigned int)value;
    while (temp > 0) {
        int rest = temp % base;
        buffer[i++] = (rest < 10) ? (rest + '0') : (rest - 10 + 'A');
        temp /= base;
    }
    buffer[i] = '\0';
    reverse(buffer, buffer + i);
    return buffer;
}

int DetectareBaza(const char* b) {
    int max_val = 0;
    for (int i = 0; b[i] != '\0'; i++) {
        if (b[i] >= '0' && b[i] <= '9') max_val = max(max_val, b[i] - '0');
        else if (b[i] >= 'A' && b[i] <= 'Z') max_val = max(max_val, b[i] - 'A' + 10);
        else if (b[i] >= 'a' && b[i] <= 'z') max_val = max(max_val, b[i] - 'a' + 10);
    }
    return max_val + 1;
}

Number::Number(const char* value, int base) {
    this->baza = base;
    this->nr = new char[strlen(value) + 1];
    strcpy(this->nr, value);
}

Number::Number(int value) {
    this->baza = 10;
    char buffer[20];
    sprintf(buffer, "%d", value);
    this->nr = new char[strlen(buffer) + 1];
    strcpy(this->nr, buffer);
}

Number::~Number() {
    delete[] this->nr;
}

Number::Number(const Number& x) {
    this->baza = x.baza;
    this->nr = new char[strlen(x.nr) + 1];
    strcpy(this->nr, x.nr);
}

Number::Number(Number&& x) noexcept {
    this->baza = x.baza;
    this->nr = x.nr;
    x.nr = nullptr;
}

void Number::SwitchBase(int newBase) {
    int val10 = strtol(this->nr, NULL, baza);
    char* noulNr = IntToStack(val10, newBase);
    delete[] this->nr;
    this->nr = new char[strlen(noulNr) + 1];
    strcpy(this->nr, noulNr);
    this->baza = newBase;
}

void Number::Print() {
    if (this->nr) cout << this->nr << endl;
}

int Number::GetDigitsCount() {
    return (int)strlen(this->nr);
}

int Number::GetBase() {
    return this->baza;
}

Number operator+(const Number& a, const Number& b) {
    int val1 = strtol(a.nr, NULL, a.baza);
    int val2 = strtol(b.nr, NULL, b.baza);
    int resBase = max(a.baza, b.baza);
    return Number(IntToStack(val1 + val2, resBase), resBase);
}

Number operator-(const Number& a, const Number& b) {
    int val1 = strtol(a.nr, NULL, a.baza);
    int val2 = strtol(b.nr, NULL, b.baza);
    int resBase = max(a.baza, b.baza);
    return Number(IntToStack(val1 - val2, resBase), resBase);
}

Number& Number::operator=(const Number& b) {
    if (this != &b) {
        delete[] nr;
        this->baza = b.baza;
        this->nr = new char[strlen(b.nr) + 1];
        strcpy(this->nr, b.nr);
    }
    return *this;
}

Number& Number::operator=(int b) {
    char* noulNr = IntToStack(b, this->baza);
    delete[] this->nr;
    this->nr = new char[strlen(noulNr) + 1];
    strcpy(this->nr, noulNr);
    return *this;
}

Number& Number::operator=(const char* b) {
    delete[] this->nr;
    this->nr = new char[strlen(b) + 1];
    strcpy(this->nr, b);
    
    return *this;
}

Number& operator+=(Number& a, const Number& b) {
    a = a + b;
    return a;
}

Number& operator-=(Number& a, const Number& b) {
    a = a - b;
    return a;
}

char& Number::operator[](int index) {
    return this->nr[index];
}

Number& Number::operator--() { 
    memmove(nr, nr + 1, strlen(nr));
    return *this;
}

Number Number::operator--(int) { 
    Number temp(*this);
    this->nr[strlen(nr) - 1] = '\0';
    return temp;
}


bool operator<(const Number& a, const Number& b) {
    return strtol(a.nr, NULL, a.baza) < strtol(b.nr, NULL, b.baza);
}
bool operator>(const Number& a, const Number& b) {
    return strtol(a.nr, NULL, a.baza) > strtol(b.nr, NULL, b.baza);
}
bool operator<=(const Number& a, const Number& b) {
    return strtol(a.nr, NULL, a.baza) <= strtol(b.nr, NULL, b.baza);
}
bool operator>=(const Number& a, const Number& b) {
    return strtol(a.nr, NULL, a.baza) >= strtol(b.nr, NULL, b.baza);
}
bool operator==(const Number& a, const Number& b) {
    return strtol(a.nr, NULL, a.baza) == strtol(b.nr, NULL, b.baza);
}
bool operator!=(const Number& a, const Number& b) {
    return strtol(a.nr, NULL, a.baza) != strtol(b.nr, NULL, b.baza);
}