#include <iostream>
#include <set>
#include <random>
#include <limits>
using namespace std;

int main() {
    std::mt19937 generator{ 42 };
    std::uniform_int_distribution<int> lottery{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
    std::set<int> s;
    for (int i = 0; i < 10000000; ++i) {
        s.insert(lottery(generator));
    }
    auto it = s.lower_bound(0);
    if (it == s.begin()) {
        std::cout << *it << '\n';
    } else if (it == s.end()) {
        --it;
        std::cout << *it << '\n';
    } else {
        int a = *it;
        --it;
        int b = *it;
        std::cout << b << " " << a << '\n';
    }
}
