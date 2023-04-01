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
    auto it = s.upper_bound(1000000000);
    s.erase(it, s.end());
    cout << "Lukuja jaljella: " << s.size() << '\n';
}
