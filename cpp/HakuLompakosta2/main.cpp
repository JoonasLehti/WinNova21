#include <iostream>
#include <map>
#include <string>
using namespace std;

struct CompareKeys {
    bool operator()(const string& lhs, const string& rhs) const {
        double lhsValue = stod(lhs.substr(0, lhs.find(' ')));
        double rhsValue = stod(rhs.substr(0, rhs.find(' ')));
        if (lhs.find("cent") != string::npos) {
            lhsValue /= 100;
        }
        if (rhs.find("cent") != string::npos) {
            rhsValue /= 100;
        }
        return lhsValue < rhsValue;
    }
};

int main() {
    map<string, int, CompareKeys> values = {
        {"1 cent", 5},
        {"2 cent", 3},
        {"5 cent", 5},
        {"10 cent", 3},
        {"50 cent", 7},
        {"1 €", 5},
        {"2 €", 3},
        {"5 €", 5},
        {"10 €", 1},
        {"20 €", 5},
        {"50 €", 8},
        {"100 €", 3}
              };

    cout << "20 centin kolikoita: " << values["20 cent"] << endl;
    cout << "50 centin kolikoita: " << values["50 cent"] << endl;

    return 0;
}
