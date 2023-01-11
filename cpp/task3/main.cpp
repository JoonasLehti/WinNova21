#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    vector<string> rivit;
    string teksti;

    ifstream tiedosto("C:\\Users\\Lennu\\Documents\\GitHub\\Joonas_Lehti\\cpp\\task3\\test.csv");

    if (tiedosto.is_open())
    {
        while (getline (tiedosto, teksti))
        {
            rivit.push_back(teksti);
        }
        tiedosto.close();
    }
    else
    {
        cout << "Tiedostoa ei ole" << endl;
    }
    cout << rivit.size() << endl;
}

