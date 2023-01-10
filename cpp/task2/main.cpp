#include <iostream>

using namespace std;

bool Karkausvuosi(int vuosi)
{
    if ((vuosi % 4 == 0 && vuosi % 100 != 0) || vuosi % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool paivamaaraTark(int &paiva, int &kuukausi, int &vuosi)
{
    if (kuukausi < 1 || kuukausi > 12)
    {
        return false;
    }

    if (vuosi < 0)
    {
        return false;
    }

    int KuukaudenPaivat = 31;
    if (kuukausi == 2)
    {
        if ((vuosi % 4 == 0 && vuosi % 100 != 0) || vuosi % 400 == 0)
        {
            KuukaudenPaivat = 29;
        }
        else
        {
            KuukaudenPaivat = 28;
        }
    }
    else if (kuukausi == 4 || kuukausi == 6 || kuukausi == 9 || kuukausi == 11)
    {
        KuukaudenPaivat = 30;
    }
    if (paiva < 1 || paiva > KuukaudenPaivat)
    {
        return false;
    }
    return true;
}

int main()
{
    string teksti;

    cout << "Anna paivamaara muodossa 31.12.1234" << endl;
    cin >> teksti;

    int paiva = stoi(teksti.substr(0, 2));
    int kuukausi = stoi(teksti.substr(3, 2));
    int vuosi = stoi(teksti.substr(6));

    if (paivamaaraTark(paiva, kuukausi, vuosi))
    {
        cout << "paivamaara kelpaa" << endl;
        if (Karkausvuosi(vuosi))
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
