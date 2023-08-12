#ifndef TEMA1_V2_SOLUTIONS_CURS_H
#define TEMA1_V2_SOLUTIONS_CURS_H

#include <iostream>
#include <vector>
#include"include/materie.h"
#include"include/student.h"

class Curs {
    Materie mat;
    int nrStudenti;
    std::vector<Student> St;

public:
    Curs();
    Curs(const Materie &mat, int nrStud_, std::vector<Student> St_);
    Curs(const Materie &other);
    Curs &operator+=(Student &other);
    Curs &operator+(Student &other);
    Curs &operator=(Curs &other);
    friend std::istream &operator>>(std::istream &in, Curs &curs);
    friend std::ostream &operator<<(std::ostream &out, Curs &curs);
    Materie materie() const;
};


#endif //TEMA1_V2_SOLUTIONS_CURS_H
