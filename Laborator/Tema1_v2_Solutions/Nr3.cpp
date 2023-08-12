//Nr. 3
//v2
#include<iostream>
#include<vector>

class Data {
    int zi;
    std::string luna = "-";
    int an;

public:
    //constructor
    Data() {}

    Data(int zi_, const std::string &luna_, int an_) : zi(zi_), luna(luna_), an(an_) {}

    //constructor de copiere
    Data(const Data &other) : zi(other.zi), luna(other.luna), an(other.an) {}

    friend std::istream &operator>>(std::istream &in, Data &data);

    friend std::ostream &operator<<(std::ostream &out, Data &data);

    Data &operator=(const Data &data);
};

std::istream &operator>>(std::istream &in, Data &data) {
    in >> data.zi >> data.luna >> data.an;
    return in;
}

std::ostream &operator<<(std::ostream &out, Data &data) {
    out << "Zi: " << data.zi << ", luna: " << data.luna << ", an: " << data.an;
    return out;
}

Data &Data::operator=(const Data &data) {
    if (this != &data) {
        zi = data.zi;
        luna = data.luna;
        an = data.an;
    }
    return *this;
}

class Proprietar {
    std::string nume;
    Data data_nasterii;

public:
    Proprietar() {}

    Proprietar(const std::string &nume_, const Data &data_nast) : nume(nume_), data_nasterii(data_nast) {}

    Proprietar(const std::string &nume_, int zi_, const std::string &luna_, int an_) : nume(nume_),
                                                                                       data_nasterii(zi_, luna_, an_) {}

    friend std::istream &operator>>(std::istream &in, Proprietar &propr);

    friend std::ostream &operator<<(std::ostream &out, Proprietar &propr);
};

std::istream &operator>>(std::istream &in, Proprietar &propr) {
    in >> propr.nume >> propr.data_nasterii;
    return in;
}

std::ostream &operator<<(std::ostream &out, Proprietar &propr) {
    out << "Proprietar: " << propr.nume << ", Data Nasterii: " << propr.data_nasterii << "\n";
    return out;
}

class Casa {
    std::string oras;
    int nrProprietari;
    std::vector<Proprietar> Prop;

public:
    Casa() : oras("-"), nrProprietari(0) {}

    explicit Casa(const std::string &oras_) : oras(oras_), nrProprietari(0) {}

    Casa(const std::string &oras_, int nrProp_) : oras(oras_), nrProprietari(nrProp_) {}

    Casa(const std::string &oras_, int nrProp_, std::vector<Proprietar> Prop_) : oras(oras_), nrProprietari(nrProp_),
                                                                                 Prop(Prop_) {}

    friend std::istream &operator>>(std::istream &in, Casa &casa);

    friend std::ostream &operator<<(std::ostream &out, Casa &casa);

    Casa &operator=(const Casa &other);

    Casa &operator+=(const Proprietar &propr);
};

std::istream &operator>>(std::istream &in, Casa &casa) {
    in >> casa.oras >> casa.nrProprietari;
    casa.Prop.resize(casa.nrProprietari);
    for (int i = 0; i < casa.nrProprietari; i++)
        in >> casa.Prop[i];
    return in;
}

std::ostream &operator<<(std::ostream &out, Casa &casa) {
    out << "Casa se afla in: " << casa.oras << ", are " << casa.nrProprietari << " proprietari: \n";
    for (int i = 0; i < casa.nrProprietari; i++)
        out << "\t-" << casa.Prop[i];
    return out;
}

Casa &Casa::operator=(const Casa &other) {
    if (this != &other) {
        oras = other.oras;
        nrProprietari = other.nrProprietari;
        Prop = other.Prop;
    }
    return *this;
}

Casa &Casa::operator+=(const Proprietar &propr) {
    nrProprietari++;
    Prop.push_back(propr);
    return *this;
}

int main() {
    Data d1(15, "iulie", 1975), d2 = d1;
    std::cout << d1 << "\n";
    std::cout << d2 << "\n";
    Proprietar p1("Ionescu", d1), p2("Popescu", 2, "ianuarie", 1980);
    std::cout << p1;
    std::cout << p2;
    Casa c1("Bucuresti"), c2;
    std::cout << c1 << "\n";
    c1 += p1;
    c1 += p2;
    std::cout << c1 << "\n";
    std::cin >> c2;
//    std::cout << c1;
    Casa c3 = c2;
    std::cout << c3;
    return 0;
}