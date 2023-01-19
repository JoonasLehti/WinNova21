#include "paivamaara.h"

bool Paivamaara::paivamaaraTark(int &paiva, int &kuukausi, int &vuosi)
{
    if(kuukausi==2 && vuosi==2023)
    {
        if(paiva>=20 && paiva<=26)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
