//Nr. 6
//v2
#include<iostream>
#include"include/materie.h"
#include"include/student.h"
#include"include/curs.h"

int main() {
    Materie m1("POO", 0), m2("Pedagogie", 1), m3;
//    if(m1==m2)
//        std::cout << "Cursuri identice";
//    else
//        std::cout << "Materii diferite";
    Student s1(12, "Ionescu", 133), s2;
//    std::cin>>s2;
//    std::cout<<s1<<s2;
    Curs c1(m1);
    c1+=s1;//adauga student s1 in lista studentilor cursului c1
    c1 = c1 + s2; //adauga student s2 in lista studentilor cursului c1
    std::cout << c1;
    Curs c2 = c1;
//    std::cout << c2;
    m3 = c2.materie();
    std::cout << m3;
    return 0;
}