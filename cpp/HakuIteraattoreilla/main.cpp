#include <iostream>
#include <vector>
#include <random>
#include <limits>
using namespace std;

int main() {
    std::mt19937 generator{ 42 };
    std::uniform_int_distribution<int> distribution{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
    std::vector<int> vec;
    for (int i = 0; i < 1000000; ++i) {
        vec.push_back(distribution(generator));
    }
    auto it = vec.begin() + 123456;
    auto end = vec.begin() + 123461;
    for (; it != end; ++it) {
        std::cout << *it << ' ';
    }
    return 0;
}
