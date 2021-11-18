#include <iostream>
#include <cmath>

using namespace std;

class Cselekedet {
    string megnevezes;
    double josagi_mertek;

public:
    Cselekedet(): megnevezes(""), josagi_mertek(0) {}

    Cselekedet(const string& megnevezes, double josagi_mertek) : megnevezes(megnevezes), josagi_mertek(josagi_mertek){}

    const string &getMegnevezes() const {
        return megnevezes;
    }

    double get_josagi_mertek() const {
        return josagi_mertek;
    }
};

struct Info {
    Cselekedet cselekedet;
    int darab = 0;
};

class Ember {
    string nev;
    Cselekedet* cselekedetek;

public:
    Ember(const string &nev, Cselekedet* cselekedetek) : nev(nev), cselekedetek(cselekedetek) {}

    bool mennyorszag() {
        int i = 0;
        while (!cselekedetek[i++].getMegnevezes().empty());

        Info infos[i];

        int aktualis_darab = 0;
        i = 0;
        while (!cselekedetek[i].getMegnevezes().empty()) {
            bool volt = false;

            for (int j = 0; j < aktualis_darab; j++) {
                if (infos[j].cselekedet.getMegnevezes() == cselekedetek[i].getMegnevezes()) {
                    infos[j].darab++;
                    volt = true;
                    break;
                }
            }

            if (!volt) {
                infos[aktualis_darab].cselekedet = cselekedetek[i];
                infos[aktualis_darab].darab = 1;
                aktualis_darab++;
            }

            i++;
        }

        double osszeg = 0;
        for (i = 0; i < aktualis_darab; i++) {
            double ertek = pow(infos[i].cselekedet.get_josagi_mertek(), infos[i].darab);
            if (infos[i].cselekedet.get_josagi_mertek() < 0) {
                ertek *= -ertek;
            }

            osszeg += ertek;
        }

        return osszeg > 0;
    }

    const string &get_nev() const {
        return nev;
    }

};

bool mennyorszagba_jut_a_kiralyno(Ember emberek[], unsigned int darab) {
    for (int i = 0; i < darab; i++){
        if(emberek[i].get_nev() == "Leenhurbertindrund kiralyno") {
            return emberek[i].mennyorszag();
        }
    }
    return false;
}
