#pragma once

class Number {
    int baza;
    char* nr;

public:
    Number(const char* value, int base);
    Number(int value); 
    ~Number();

    Number(const Number& x);
    Number(Number&& x) noexcept;

    friend Number operator+(const Number& a, const Number& b);
    friend Number operator-(const Number& a, const Number& b);

    Number& operator=(const Number& b);
    Number& operator=(int b);
    Number& operator=(const char* b);

    friend Number& operator+=(Number& a, const Number& b);
    friend Number& operator-=(Number& a, const Number& b);

    Number& operator--();    
    Number operator--(int);  

    char& operator[](int index);

    friend bool operator<(const Number& a, const Number& b);
    friend bool operator>(const Number& a, const Number& b);
    friend bool operator<=(const Number& a, const Number& b);
    friend bool operator>=(const Number& a, const Number& b);
    friend bool operator==(const Number& a, const Number& b);
    friend bool operator!=(const Number& a, const Number& b);

    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount();
    int GetBase();
};