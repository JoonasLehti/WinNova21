#include <iostream>
#include <set>
#include <random>
#include <limits>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    mt19937 generator{ 42 };
    uniform_int_distribution<int> lottery{ numeric_limits<int>::min(), numeric_limits<int>::max() };
    set<int> s1;
    for (int i = 0; i < 1000000; ++i) {
        s1.insert(lottery(generator));
    }
    set<int> s2;
    for (int i = 0; i < 1000000; ++i) {
        s2.insert(lottery(generator));
    }
    cout << "Samat arvot:";
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';
}
