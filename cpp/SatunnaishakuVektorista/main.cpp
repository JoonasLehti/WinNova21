#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int main() {
    mt19937 generator{ 42 };
    uniform_int_distribution<int> distribution{ numeric_limits<int>::min(), numeric_limits<int>::max() };

    vector<int> vec;
    for (int i = 0; i < 10000000; ++i) {
        vec.push_back(distribution(generator));
    }
    vector<int> values = { -1245214370, 122460941, -122460941, 1385283091 };
    for (int value : values) {
        auto it = find(vec.begin(), vec.end(), value);
        if (it != vec.end()) {
            cout << "Arvo: " << value << " loytyy indeksista: " << distance(vec.begin(), it) << '\n';
        } else {
            cout << "Arvo: " << value << " Ei loydy\n";
        }
    }
}
