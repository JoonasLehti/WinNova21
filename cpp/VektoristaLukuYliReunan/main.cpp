#include <iostream>
#include <vector>
#include <random>
using namespace std;

int main() {
    mt19937 generator{ 42 };
    uniform_int_distribution<int> distribution{ numeric_limits<int>::min(), numeric_limits<int>::max() };
    vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(distribution(generator));
    }
    cout << "Arvot 0 - 20: ";
    for (int i = 0; i < 20; ++i) {
        cout << vec[i] << ' ';
    }
    cout << '\n';
}

//Mitä tapahtuu, jos hakasulku-operaattorin sijaan käytät metodia at().
//[] operaatio antaa mita sattuu arvoja kun at() antaa out_of_range errorin
