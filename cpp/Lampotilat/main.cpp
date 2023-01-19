#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct SaaTiedot
{
    int vuosi;
    int kuukausi;
    int paiva;
    float ilmanlampo;
    float Ylinlampo;
    float Alinlampo;
};

int main()
{
    vector<SaaTiedot> data;
    string teksti;
    ifstream tiedosto("lentokentta.csv");

    if (tiedosto.is_open())
    {
        while (getline(tiedosto, teksti))
        {
            SaaTiedot tempData;
            stringstream ss(teksti);
            ss >> tempData.vuosi >> tempData.kuukausi >> tempData.paiva >> tempData.ilmanlampo >> tempData.Ylinlampo >> tempData.Alinlampo;
            data.push_back(tempData);
         }
        tiedosto.close();
    }
    else
    {
        cout << "Tiedostoa ei ole" << endl;
    }
        float maxYlinlampo = data[1].Ylinlampo;
        float minAlinlampo = data[1].Alinlampo;
        int maxYlinlampoIndex = 1;
        int minAlinlampoIndex = 1;

        for (unsigned int i = 2; i < data.size(); i++)
        {
            if (data[i].Ylinlampo >= maxYlinlampo)
            {
                maxYlinlampo = data[i].Ylinlampo;
                maxYlinlampoIndex = i;
            }

            if (data[i].Alinlampo < minAlinlampo)
            {
                minAlinlampo = data[i].Alinlampo;
                minAlinlampoIndex = i;
            }
        }

        cout << "Ylinlampo: " << maxYlinlampo << " on " << data[maxYlinlampoIndex].paiva << "." << data[maxYlinlampoIndex].kuukausi << "." << data[maxYlinlampoIndex].vuosi << endl;
        cout << "Alinlampo: " << minAlinlampo << " on " << data[minAlinlampoIndex].paiva << "." << data[minAlinlampoIndex].kuukausi << "." << data[minAlinlampoIndex].vuosi << endl;
}
