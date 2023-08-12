#include "include/student.h"

Student::Student() : nrMatricol(0), nume("-"), grupa(0){}

Student::Student(int nrMat_, const std::string &nume_, int grupa_) : nrMatricol(nrMat_), nume(nume_), grupa(grupa_) {}

std::istream &operator>>(std::istream &in, Student &stud) {
    in >> stud.nrMatricol >> stud.nume >> stud.grupa;
    return in;
}

std::ostream &operator<<(std::ostream &out, Student &stud) {
    out << "Nr Matricol: " << stud.nrMatricol << ", nume: " << stud.nume << ", grupa: " << stud.grupa << "\n";
    return out;
}
