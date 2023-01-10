#include <iostream>

using namespace std;

void AnnaLuku(int &luku1, int &luku2)
{
    cout << "Anna ensimmainen luku: ";
    cin >> luku1;
    cout << "Anna toinen luku: ";
    cin >> luku2;
}

void TulostaLuvut(int luku1, int luku2)
{
    cout << "Lukujen summa on: " << luku1 + luku2 << endl;
    cout << "Lukujen erotus on: " << luku1 - luku2 << endl;
}

int main()
{
    int x, y;
    AnnaLuku(x, y);
    TulostaLuvut(x, y);
    return 0;
}
