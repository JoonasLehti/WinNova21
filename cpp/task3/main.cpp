#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int miehet = 0;
    int naiset = 0;
    vector<string> rivit;
    string teksti;

    ifstream tiedosto("C:\\Users\\Lennu\\Documents\\GitHub\\Joonas_Lehti\\cpp\\task3\\test.csv");

    if (tiedosto.is_open())
    {
        while (getline (tiedosto, teksti))
        {
            rivit.push_back(teksti);

            stringstream ssin(teksti);
            string osat[5];
            int i = 0;
            while(getline(ssin, osat[i], ','))
            {
                i++;
            }
            if (osat[2] == "M")
            {
                miehet++;
            }
            else if (osat[2] == "F")
            {
                naiset++;
            }
        }
        tiedosto.close();
    }
    else
    {
        cout << "Tiedostoa ei ole" << endl;
    }
    cout << rivit.size() << endl;
    cout << "Miehia: " << miehet << endl;
    cout << "Naisia: " << naiset << endl;
}

