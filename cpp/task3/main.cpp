#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct date {
    int year;
    int month;
    int day;
};

int main()
{
    int miehet = 0;
    int naiset = 0;

    vector<int> vuosi;
    vector<int> kuukaudet;
    vector<int> paivat;
    vector<date> dates;

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
            string syntyma = osat[3];

            string vuos = syntyma.substr(0, 4);
            int year = (stoi(vuos));

            string kk = syntyma.substr(5, 2);
            int month = (stoi(kk));

            string pv = syntyma.substr(8, 2);
            int day = (stoi(pv));

            date dt = {year, month, day};
            dates.push_back(dt);


        }

        cout << "Rivien maara: " << rivit.size() << endl;
        cout << "Miehia: " << miehet << endl;
        cout << "Naisia: " << naiset << endl;

        cout << endl;
        cout << "Vanhin tyontekija: " << endl;

        sort(dates.begin(), dates.end(), [](const date &a, const date &b) {
            return a.year < b.year || (a.year == b.year && (a.month < b.month || (a.month == b.month && a.day < b.day)));
        });

        char buffer[20];
        sprintf(buffer, "%04d-%02d-%02d", dates[0].year, dates[0].month, dates[0].day);

        tiedosto.close();
        tiedosto.open("C:\\Users\\Lennu\\Documents\\GitHub\\Joonas_Lehti\\cpp\\task3\\test.csv");

            if (tiedosto.is_open())
            {
                while (getline (tiedosto, teksti))
                {
                    if (teksti.find(buffer, 0) != string::npos)
                    {
                        cout << teksti << endl;
                    }
                }
                tiedosto.close();
            }
            else
            {
                cout << "Tiedostoa ei ole" << endl;
            }
    }
    else
    {
        cout << "Tiedostoa ei ole" << endl;
    }
}
