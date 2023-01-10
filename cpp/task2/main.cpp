#include <iostream>
#include "paivamaara.h"
using namespace std;

int main()
{
    string teksti;

    Paivamaara d;

    cout << "Anna paivamaara muodossa 31.12.1234" << endl;
    cin >> teksti;

    int paiva = stoi(teksti.substr(0, 2));
    int kuukausi = stoi(teksti.substr(3, 2));
    int vuosi = stoi(teksti.substr(6));

    if (d.paivamaaraTark(paiva, kuukausi, vuosi))
    {
        cout << "paivamaara kelpaa" << endl;
        if (d.Karkausvuosi(vuosi))
        {
            cout << "on karkausvuosi" << endl;
        }
        else
        {
            cout << "ei ole karkausvuosi" << endl;
        }
    }
    else
    {
        cout << "paivamaara ei kelpaa." << endl;
    }
        return 0;
}
