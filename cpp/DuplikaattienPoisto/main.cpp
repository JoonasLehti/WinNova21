#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <limits>
using namespace std;

int main() {
    mt19937 generator{ 42 };
    uniform_int_distribution<int> lottery{ numeric_limits<int>::min(), numeric_limits<int>::max() };
    vector<int> vec;
    for (int i = 0; i < 10000000; ++i) {
        vec.push_back(lottery(generator));
    }
    set<int> s(vec.begin(), vec.end());
    vec.assign(s.begin(), s.end());
    cout << vec.size() << endl;
}
