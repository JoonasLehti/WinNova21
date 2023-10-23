#include <iostream>
#include <vector>
#include <random>
#include <limits>
using namespace std;

int main() {
    mt19937 generator{ 42 };
    uniform_int_distribution<int> distribution{ numeric_limits<int>::min(), numeric_limits<int>::max() };
    vector<int> vec;
    for (int i = 0; i < 1000000; ++i) {
        vec.push_back(distribution(generator));
    }
    auto it = vec.begin() + 123456;
    auto end = vec.begin() + 123461;
    for (; it != end; ++it) {
        cout << *it << ' ';
    }
    return 0;
}
