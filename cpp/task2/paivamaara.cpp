#include "paivamaara.h"

bool Paivamaara::Karkausvuosi(int vuosi)
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

bool Paivamaara::paivamaaraTark(int &paiva, int &kuukausi, int &vuosi)
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
