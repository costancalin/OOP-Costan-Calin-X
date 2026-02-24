#pragma once
class Student
{
    const char* nume;
    int mate, engleza, istorie, medie;
public:
    void setnume(const char* a);
    const char* getnume();

    void setmate(int x);
    int getmate();

    void setengleza(int x);
    int getengleza();

    void setistorie(int x);
    int getistorie();

    double getmedie();
};


