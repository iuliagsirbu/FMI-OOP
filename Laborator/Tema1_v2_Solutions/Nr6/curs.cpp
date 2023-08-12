#include "include/curs.h"
#include "include/materie.h"
#include <iostream>

Curs::Curs() : nrStudenti(0) {}

Curs::Curs(const Materie &mat_, int nrStud_, const std::vector<Student> St_) : mat(mat_), nrStudenti(nrStud_), St(St_) {}

Curs::Curs(const Materie &other) : mat(other), nrStudenti(0) {}

Curs &Curs::operator+=(Student &other) {
    nrStudenti++;
    St.push_back(other);
    return *this;
}

Curs &Curs::operator+(Student &other) {
    nrStudenti++;
    St.push_back(other);
    return *this;
}

Curs &Curs::operator=(Curs &other) {
    if (this != &other)
    {
        mat = other.mat;
        nrStudenti = other.nrStudenti;
        St = other.St;
    }
    return *this;
}

std::istream &operator>>(std::istream &in, Curs &curs) {
    in >> curs.mat >> curs.nrStudenti;
    curs.St.resize(curs.nrStudenti);
    for(int i=0;i<curs.nrStudenti;i++)
        in >> curs.St[i];
    return in;
}

std::ostream &operator<<(std::ostream &out, Curs &curs) {
    out << "Curs => " << curs.mat << ", are " << curs.nrStudenti << " studenti: \n";
    for(int i=0;i<curs.nrStudenti;i++)
        out << "\t-" << curs.St[i];
    return out;
}

Materie Curs::materie() const{
    return mat;
}








