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
    auto it = s.lower_bound(0);
    if (it == s.begin()) {
        cout << *it << '\n';
    } else if (it == s.end()) {
        --it;
        cout << *it << '\n';
    } else {
        int a = *it;
        --it;
        int b = *it;
        cout << b << " " << a << '\n';
    }
}
