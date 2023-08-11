//Nr. 2
//v2
#include<iostream>
#include<vector>

class Ingredient {
    std::string nume = "-";
    float pret;
    int cantitate;

public:
    Ingredient() : pret(0.0), cantitate(0) {}

    explicit Ingredient(const std::string &nume_) : nume(nume_), pret(0.0), cantitate(0) {}

    Ingredient(const std::string &nume_, float pret_) : nume(nume_), pret(pret_), cantitate(0) {}

    Ingredient(const std::string &nume_, float pret_, int cant_) : nume(nume_), pret(pret_), cantitate(cant_) {}

    Ingredient(const Ingredient &other) : nume(other.nume), pret(other.pret), cantitate(other.cantitate) {}

    friend std::istream &operator>>(std::istream &in, Ingredient &ing);

    friend std::ostream &operator<<(std::ostream &out, Ingredient &ing);

    Ingredient &operator+=(int value);

    Ingredient &operator=(const Ingredient &other);
};

std::istream &operator>>(std::istream &in, Ingredient &ing) {
    in >> ing.nume >> ing.pret >> ing.cantitate;
    return in;
}

std::ostream &operator<<(std::ostream &out, Ingredient &ing) {
    out << "Ingredient: " << ing.nume << ", Pret: " << ing.pret << ", Cantitate: " << ing.cantitate;
    return out;
}

Ingredient &Ingredient::operator+=(int value) {
    cantitate += value;
    return *this;
}

Ingredient &Ingredient::operator=(const Ingredient &other) {
    if (this != &other) {
        nume = other.nume;
        pret = other.pret;
        cantitate = other.cantitate;
    }
    return *this;
}

class Pizza {
    std::string denumire;
    int nrIngrediente;
    std::vector<Ingredient> Ingr;

public:
    Pizza() : denumire("-"), nrIngrediente(0) {}

    explicit Pizza(const std::string &denum_) : denumire(denum_), nrIngrediente(0) {}

    Pizza(const std::string &denum_, int nrIngr_) : denumire(denum_), nrIngrediente(nrIngr_) {}

    Pizza(const std::string &denum_, int nrIngr_, const std::vector<Ingredient> Ingr_) : denumire(denum_),
                                                                                         nrIngrediente(nrIngr_),
                                                                                         Ingr(Ingr_) {}

    friend std::istream &operator>>(std::istream &in, Pizza &pizza);

    friend std::ostream &operator<<(std::ostream &out, Pizza &pizza);

    Pizza &operator+(const Ingredient &ingr);

    bool operator>(const Pizza &other) const;
};

std::istream &operator>>(std::istream &in, Pizza &pizza) {
    in >> pizza.denumire >> pizza.nrIngrediente;
    pizza.Ingr.resize(pizza.nrIngrediente);
    for (int i = 0; i < pizza.nrIngrediente; i++)
        in >> pizza.Ingr[i];
    return in;
}

std::ostream &operator<<(std::ostream &out, Pizza &pizza) {
    out << "Pizza: " << pizza.denumire << ", nrIngrediente: " << pizza.nrIngrediente;
    if (pizza.nrIngrediente != 0) {
        out << ", Ingrediente: \n";
        for (int i = 0; i < pizza.nrIngrediente; i++)
            out << "\t- " << pizza.Ingr[i] << "\n";
    }
    return out;
}

Pizza &Pizza::operator+(const Ingredient &ingr) {
    nrIngrediente++;
    Ingr.push_back(ingr);
    return *this;
}

bool Pizza::operator>(const Pizza &other) const {
    return nrIngrediente > other.nrIngrediente;
}

int main() {
    Ingredient i1("Piper", 0.5, 10), i2("Nimic", 0.0, 0);
    std::cout << i1 << "\n" << i2 << "\n";
//    Ingredient i3, i4("Sare"), i5("Ghimbir", 2);
//    std::cout << i3 << "\n" << i4;
    std::cout << "\n~~~~~~~~~~~~~~\n";
    std::cout << "Inaine de op +=: " << i1;
    i1 += 500; //Aduna o valoare la cantitatea disponibila
    std::cout << "\nDupa op +=: " << i1 << "\n";
    Ingredient i3 = i1, i4, i5(i1);
    i4 = i1;
    std::cout << "op=: " << i3 << "\n" << i4 << "\n" << i5 << "\n";
    std::cout << "\n~~~~~~~~~~~~~~\n";
    Pizza pizza1("Clasic"), pizza2;
    std::cout << pizza1 << "\n" << pizza2 << "\n";
//    Pizza pizza3;
//    std::cin >> pizza3;
//    std::cout << pizza3;
    pizza1 = pizza1 + i1;
    std::cout << pizza1 << "\n";
    if (pizza1 > pizza2) std::cout << "pizza1 are mai multe ingrediente decat pizza2";
    else std::cout << "pizza2 are mai multe ingrediente decat pizza1";
    return 0;
}