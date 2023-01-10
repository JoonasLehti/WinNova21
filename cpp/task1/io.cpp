#include <iostream>
#include "io.h"
using namespace std;

void io::AnnaLuku(int &luku1, int &luku2)
{
    cout << "Anna ensimmainen luku: ";
    cin >> luku1;
    cout << "Anna toinen luku: ";
    cin >> luku2;
}

void io::TulostaLuvut(int luku1, int luku2)
{
    cout << "Lukujen summa on: " << luku1 + luku2 << endl;
    cout << "Lukujen erotus on: " << luku1 - luku2 << endl;
}
