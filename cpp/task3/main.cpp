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

class Employee {
public:
    Employee(string name, string gender, int year, int month, int day) {
        this->name = name;
        this->gender = gender;
        this->dob.year = year;
        this->dob.month = month;
        this->dob.day = day;
    }

    string getName() const {
        return name;
    }

    string getGender() const {
        return gender;
    }

    date getDOB() const {
        return dob;
    }

private:
    string name;
    string gender;
    date dob;
};

int main()
{
    int miehet = 0;
    int naiset = 0;

    vector<Employee> employees;

    vector<string> rivit;
    string teksti;

    ifstream tiedosto("test.csv");

    if (tiedosto.is_open())
    {
        while (getline(tiedosto, teksti))
        {
            rivit.push_back(teksti);

            stringstream ssin(teksti);
            string osat[5];
            int i = 0;

            while(getline(ssin, osat[i], ','))
            {
                i++;
            }

            string name = osat[0];
            string gender = osat[2];

            string syntyma = osat[3];
            string vuos = syntyma.substr(0, 4);
            int year = (stoi(vuos));
            string kk = syntyma.substr(5, 2);
            int month = (stoi(kk));
            string pv = syntyma.substr(8, 2);
            int day = (stoi(pv));

            Employee employee(name, gender, year, month, day);
            employees.push_back(employee);

            if (gender == "M")
            {
                miehet++;
            }
            else if (gender == "F")
            {
                naiset++;
            }
        }

        cout << "Rivien maara: " << rivit.size() << endl;
        cout << "Miehia: " << miehet << endl;
        cout << "Naisia: " << naiset << endl;

        cout << endl;
        cout << "Vanhin tyontekija: " << endl;

        sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
            return a.getDOB().year < b.getDOB().year || (a.getDOB().year == b.getDOB().year && (a.getDOB().month < b.getDOB().month || (a.getDOB().month == b.getDOB().month && a.getDOB().day < b.getDOB().day)));
        });

        cout << "Name: " << employees[0].getName() << endl;
        cout << "Gender: " << employees[0].getGender() << endl;
        cout << "Date of birth: " << setw(4) << setfill('0') << employees[0].getDOB().year << "-"
             << setw(2) << setfill('0') << employees[0].getDOB().month << "-"
             << setw(2) << setfill('0') << employees[0].getDOB().day << endl;

        tiedosto.close();
    }
    else
    {
        cout << "Tiedostoa ei ole" << endl;
    }
}
