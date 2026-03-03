#include <iostream>
#include "Math.h"
#include "Canvas.h"

using namespace std;

int main() {
    cout << Math::Add(10, 20) << endl;
    cout << Math::Add(10, 20, 30) << endl;
    cout << Math::Add(2.5, 4.5) << endl;
    cout << Math::Add(1.5, 2.5, 3.5) << endl;

    cout << Math::Mul(5, 5) << endl;
    cout << Math::Mul(2, 3, 4) << endl;
    cout << Math::Mul(2.5, 2.0) << endl;
    cout << Math::Mul(1.1, 2.0, 3.0) << endl;

    cout << Math::Add(4, 1, 2, 3, 4) << endl;

    char* s = Math::Add("OO", "P"); cout << s << endl;

    Canvas c(20, 10);
    c.DrawLine(0, 0, 19, 0, '-');
    c.DrawLine(0, 9, 19, 9, '-');
    c.DrawLine(0, 0, 0, 9, '|');
    c.DrawLine(19, 0, 19, 9, '|');
    c.DrawLine(2, 2, 17, 7, 'P');
    c.DrawLine(17, 2, 2, 7, 'O');
   
    c.Print();
        

    return 0;
}