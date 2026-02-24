#include <iostream>
#include "NumberList.h"
#include "Student.h"
#include "globals.h" 
using namespace std;

int main() {
    
  
    NumberList lista;
    lista.Init();

    lista.Add(10);
    lista.Add(5);
    lista.Add(1);
    lista.Add(8);
    lista.Add(3);

    cout << "Lista inainte de sortare este  ";
    lista.Print();

    lista.Sort();

    cout << "Lista dupa sortare este ";
    lista.Print();
    cout << endl << endl;


    
    Student s1, s2;

   
    s1.setnume("Ionescu");
    s1.setmate(9);
    s1.setengleza(8);
    s1.setistorie(10);

    
    s2.setnume("Popescu");
    s2.setmate(7);
    s2.setengleza(10);
    s2.setistorie(8);

    cout << "Student 1: " << s1.getnume() << " : Medie: " << s1.getmedie() << endl;
    cout << "Student 2: " << s2.getnume() << " : Medie: " << s2.getmedie() << endl;
    

    
    cout << "Comparare nume Ionescu Popescu: " << compname(s1, s2) << " (asteptat -1)" << endl;
    cout << "Comparare mate (9 vs 7): " << compmate(s1, s2) << " (1)" << endl;
    cout << "Comparare engleza (8 vs 10): " << compengleza(s1, s2) << " (-1)" << endl;
    cout << "Comparare medie: " << compmedie(s1, s2) << " (1)" << endl;

    return 0;
}