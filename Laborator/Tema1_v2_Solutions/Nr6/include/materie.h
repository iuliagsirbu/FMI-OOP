#ifndef TEMA1_V2_SOLUTIONS_MATERIE_H
#define TEMA1_V2_SOLUTIONS_MATERIE_H

#include<iostream>

class Materie {
    std::string denumire;
    int optional;

public:
    Materie();

    Materie(const std::string &denumire_, int opt_);

    bool operator==(const Materie &other) const;

    Materie &operator=(const Materie &other);

    friend std::istream &operator>>(std::istream &in, Materie &mat);

    friend std::ostream &operator<<(std::ostream &out, Materie &mat);
};


#endif //TEMA1_V2_SOLUTIONS_MATERIE_H
