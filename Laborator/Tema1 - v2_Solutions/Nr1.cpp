#include<iostream>
#include<vector>

class BonDeMasa{
    int id;
    std::string emitent;
    float valoare;

public:
    BonDeMasa() {}
    BonDeMasa(int id_, std::string emitent_, float valoare_) : id(id_), emitent(emitent_), valoare(valoare_) {}
    BonDeMasa operator=(const BonDeMasa& other);
    friend std::istream& operator>>(std::istream& in, BonDeMasa &bon) {
        std::cout << "\nIntroduceti date despre bon: \n";
        std::cout << "Id bon: ";
        in >> bon.id;
        std::cout << "Nume emitent bon: ";
        in >> bon.emitent;
        std::cout << "Valoare bon: ";
        in >> bon.valoare;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const BonDeMasa& bon) {
        std::cout << "Toate datele despre bon: \n";
        std::cout << "Id bon: ";
        out << bon.id << "\n";
        std::cout << "Nume emitent bon: ";
        out << bon.emitent << "\n";
        std::cout << "Valoare bon: ";
        out << bon.valoare << "\n";
        return out;
    }
};

BonDeMasa BonDeMasa::operator=(const BonDeMasa& other) {
    if(this != &other) {
        id = other.id;
        emitent = other.emitent;
        valoare = other.valoare;
    }
    return *this;
}

class Angajat{
    int id;
    std::string nume;
    int nrBonuri;
    std::vector<BonDeMasa> bonuri;
public:
    Angajat() {}
    Angajat(int id_, const std::string& nume_, int nrBonuri_ = 0) : id(id_), nume(nume_), nrBonuri(nrBonuri_), bonuri(std::vector<BonDeMasa>()) {}
    Angajat(const Angajat& other) : id(other.id), nume(other.nume), nrBonuri(other.nrBonuri),bonuri(other.bonuri) {}
    Angajat operator*=(const BonDeMasa& other);
    Angajat operator=(Angajat& other);
    bool operator<(const Angajat& other) const;
    friend std::istream& operator>>(std::istream& in, Angajat &angajat) {
        std::cout << "\nIntroduceti date despre angajat: \n";
        std::cout << "Id angajat: ";
        in >> angajat.id;
        std::cout << "Nume angajat: ";
        in >> angajat.nume;
        std::cout << "Nr Bonuri angajat: ";
        in >> angajat.nrBonuri;
        angajat.bonuri.resize(angajat.nrBonuri);
        std::cout << "\nIntroduceti bonurile: ";
        for(int i=0;i<angajat.nrBonuri;i++) {
            in >> angajat.bonuri[i];
        }
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, Angajat& angajat) {
        std::cout << "Toate datele despre angajat: \n";
        std::cout << "Id angajat: ";
        out << angajat.id << "\n";
        std::cout << "Nume angajat: ";
        out<<angajat.nume << "\n";
        std::cout << "Nr bonuri angajat: ";
        out << angajat.nrBonuri <<"\n";
        if(angajat.nrBonuri != 0) {
            std::cout << "Bonuri angajat: \n";
            for (int i = 0; i < angajat.nrBonuri; i++)
                out << angajat.bonuri[i] << "\n";
        }
        return out;
    }

    void afiseaza(){
        std::cout << *this;
    }
};

Angajat Angajat::operator*=(const BonDeMasa &other) {
    bonuri.push_back(other);
    nrBonuri++;
    return *this;
}

Angajat Angajat::operator=(Angajat &other) {
    if(this != &other) {
        id = other.id;
        nume = other.nume;
        nrBonuri = other.nrBonuri;
        bonuri = other.bonuri;
    }
    return *this;
}

bool Angajat::operator<(const Angajat &other) const {
    return id < other.id;
}

int main()
{
    BonDeMasa b1(1, "GustoPass", 9.35), b2, b3;
    b3 = b1;
//    std::cout << b3;
    Angajat a1(22,"Ionescu"), a2;
//    std::cout << a1;
//    std::cin >> b2;
//    std::cin >> a2;
    Angajat a3(a1), a4;
    std::cout << a1;
    a1*=b3;
    std::cout << "\n" << a1;
    a3.afiseaza();
    a3 = a1;
    a3.afiseaza();
    std::cin >> a2;
    if(a1 < a2) std::cout << "Angajatul " << a1 << "are id-ul mai mic decat " << a2;
    return 0;
}