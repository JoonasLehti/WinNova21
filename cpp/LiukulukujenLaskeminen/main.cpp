#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int main() {
    mt19937 generator{ 42 };
    uniform_real_distribution<float> distribute{ -1e6, 1e6 };
    vector<float> vec;
    for (int i = 0; i < 10000000; ++i) {
        vec.push_back(distribute(generator));
    }
    int count = count_if(vec.begin(), vec.end(), [](float x) { return x < 1; });
    cout << "Arvoja jokta ovat pienempia kuin 1: " << count << '\n';
}
