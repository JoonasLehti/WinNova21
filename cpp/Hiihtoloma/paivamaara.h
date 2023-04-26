#ifndef PAIVAMAARA_H
#define PAIVAMAARA_H

class Paivamaara {
public:
    Paivamaara() : paiva(0), kuukausi(0), vuosi(0) {}
    Paivamaara(int p, int k, int v) : paiva(p), kuukausi(k), vuosi(v) {}

    bool paivamaaraTark(int& paiva, int& kuukausi, int& vuosi);

    bool operator<(const Paivamaara& other) const;
    bool operator<=(const Paivamaara& other) const;
    bool operator>(const Paivamaara& other) const;
    bool operator>=(const Paivamaara& other) const;
    bool operator==(const Paivamaara& other) const;
    bool operator!=(const Paivamaara& other) const;

private:
    int paiva;
    int kuukausi;
    int vuosi;
};


#endif // PAIVAMAARA_H
