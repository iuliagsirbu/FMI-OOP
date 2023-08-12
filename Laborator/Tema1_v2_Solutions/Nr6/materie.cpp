#include "include/materie.h"

Materie::Materie() : denumire("-"), optional(0) {}

Materie::Materie(const std::string &denumire_, int opt_) : denumire(denumire_), optional(opt_) {}

bool Materie::operator==(const Materie &other) const {
    return (denumire == other.denumire && optional == other.optional);
}

std::istream &operator>>(std::istream &in, Materie &mat) {
    in >> mat.denumire >> mat.optional;
    return in;
}

std::ostream &operator<<(std::ostream &out, Materie &mat) {
    out << "Materie: " << mat.denumire << ", optional: " << mat.optional;
    return out;
}

Materie &Materie::operator=(const Materie &other) {
    if (this != &other) {
        denumire = other.denumire;
        optional = other.optional;
    }
    return *this;
}
