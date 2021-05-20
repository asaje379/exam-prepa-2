#include <bits/stdc++.h>

using namespace std;

enum TypePerso {
    PIRATE,
    MARINE,
    REVO,
    SHISHIBUKAI
} TYPE_PERSO;

string getTypePerso(TypePerso t) {
    switch(t) {
        case PIRATE: return "PIRATE";
        case MARINE: return "MARINE";
        case REVO: return "REVO";
        case SHISHIBUKAI: return "SHISHIBUKAI";
    }
}

class Attaque
{
private:
    string nom;
    int degat;

public:
    Attaque(string n, int d) : nom(n), degat(d) {}
    const string getNom() { return nom; }
    const int getDegat() { return degat; }
    friend ostream &operator<<(ostream &out, const Attaque &a)
    {
        out << a.nom;
        return out;
    }
};

class Personnage
{
protected:
    string nom;
    vector<Attaque *> attaques;
    string fruit;
    int degatFruit;
    int forceBrut;
    int vitesse;
    int endurance;
    int resistance;

public:
    Personnage(string n, vector<Attaque *> a, string f, int df, int fb, int v, int e, int r)
        : nom(n), attaques(a), fruit(f), degatFruit(df), forceBrut(fb), vitesse(v),
          endurance(e), resistance(r)
    {
    }
    virtual void sePresenter() = 0;
    Attaque *choisirAttaque()
    {
        const int nb = rand() % this->attaques.size();
        return this->attaques[nb];
    }
    void attaquer(Personnage &cible)
    {
        Attaque *a = choisirAttaque();
        cout << *this << " attaque en utilisant son " << a->getNom() << "(" << a->getDegat() << "p)" << endl;
        // Le reste du code a ecrire ici ...
    }
    friend ostream &operator<<(ostream &out, const Personnage &p)
    {
        out << p.nom;
        return out;
    }
};

class Pirate : public Personnage
{
public:
    const static TypePerso type = PIRATE;
    Pirate(string n, vector<Attaque *> a, string f, int df, int fb, int v, int e, int r)
        : Personnage(n, a, f, df, fb, v, e, r)
    {
    }
    virtual void sePresenter()
    {
        cout << "Je m'appelle " << *this << " et je suis un " << getTypePerso(Pirate::type) << "." << endl;
    }
};

int main()
{
    srand(time(NULL));
    Pirate luffy("Luffy", {
        new Attaque("Raffale", 10),
        new Attaque("Jet Pistol", 100),
        new Attaque("Elephant Gun", 120),
        new Attaque("Kong Gun", 300),
        new Attaque("King Cobra", 500),

    }, "Gomu gomu", 100, 500, 700, 800, 500);

    Pirate lucci("Rob Lucci", {
        new Attaque("Pas de lune", 0),
        new Attaque("Incision", 0),
        new Attaque("Lame de Rasoir", 120),
        new Attaque("Pied Ouragan", 150),
        new Attaque("Index Gun", 500),

    }, "Neko neko", 100, 500, 700, 800, 500);

    luffy.sePresenter();
    lucci.sePresenter();
    luffy.attaquer(lucci);
    lucci.attaquer(luffy);

    return 0;
}