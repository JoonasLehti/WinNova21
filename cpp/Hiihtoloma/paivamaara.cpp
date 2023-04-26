#include "paivamaara.h"

bool Paivamaara::paivamaaraTark(int& paiva, int& kuukausi, int& vuosi) {
    Paivamaara alkupvm(20, 2, 2023);
    Paivamaara loppupvm(26, 2, 2023);

    Paivamaara tarkistettava(paiva, kuukausi, vuosi);

    return (tarkistettava >= alkupvm && tarkistettava <= loppupvm);
}

bool Paivamaara::operator<(const Paivamaara& other) const {
    return (vuosi < other.vuosi)
           || (vuosi == other.vuosi && kuukausi < other.kuukausi)
           || (vuosi == other.vuosi && kuukausi == other.kuukausi && paiva < other.paiva);
}

bool Paivamaara::operator<=(const Paivamaara& other) const {
    return (*this < other) || (*this == other);
}

bool Paivamaara::operator>(const Paivamaara& other) const {
    return !(*this <= other);
}

bool Paivamaara::operator>=(const Paivamaara& other) const {
    return !(*this < other);
}

bool Paivamaara::operator==(const Paivamaara& other) const {
    return (paiva == other.paiva && kuukausi == other.kuukausi && vuosi == other.vuosi);
}

bool Paivamaara::operator!=(const Paivamaara& other) const {
    return !(*this == other);
}
