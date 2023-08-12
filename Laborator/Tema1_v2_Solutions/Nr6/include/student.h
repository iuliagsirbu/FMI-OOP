#ifndef TEMA1_V2_SOLUTIONS_STUDENT_H
#define TEMA1_V2_SOLUTIONS_STUDENT_H

#include<iostream>

class Student {
    int nrMatricol;
    std::string nume;
    int grupa;

public:
    Student();
    Student(int nrMat_, const std::string &nume_, int grupa_);
    friend std::istream &operator>>(std::istream &in, Student &stud);
    friend std::ostream &operator<<(std::ostream &out, Student &stud);
};


#endif //TEMA1_V2_SOLUTIONS_STUDENT_H
