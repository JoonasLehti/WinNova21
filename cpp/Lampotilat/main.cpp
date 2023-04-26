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
            string value;
            try
            {
                getline(ss, value, '\t'); tempData.vuosi = stoi(value);
                getline(ss, value, '\t'); tempData.kuukausi = stoi(value);
                getline(ss, value, '\t');tempData.paiva = stoi(value);
                getline(ss, value, '\t'); tempData.ilmanlampo = stof(value);
                getline(ss, value, '\t'); tempData.Ylinlampo = stof(value);
                getline(ss, value); tempData.Alinlampo = stof(value);
                data.push_back(tempData);
            }
            catch (const invalid_argument& e)
            {
            }
        }
        tiedosto.close();
    }
    else
    {
        cout << "Tiedostoa ei ole" << endl;
    }
        float maxYlinlampo = data[0].Ylinlampo;
        float minAlinlampo = data[0].Alinlampo;
        int maxYlinlampoIndex = 0;
        int minAlinlampoIndex = 0;

        for (unsigned int i = 0; i < data.size(); i++)
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
