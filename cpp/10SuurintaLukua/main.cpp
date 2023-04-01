#include <iostream>
#include <set>
#include <random>
#include <limits>
using namespace std;

int main() {
    mt19937 generator{ 42 };
    uniform_int_distribution<int> lottery{ numeric_limits<int>::min(), numeric_limits<int>::max() };
    set<int> s;
    for (int i = 0; i < 10000000; ++i) {
        s.insert(lottery(generator));
    }
    cout << "10 suurinta arvoa:";
    auto it = s.rbegin();
    for (int i = 0; i < 10 && it != s.rend(); ++i, ++it) {
        cout << " " << *it;
    }
    cout << '\n';
}
