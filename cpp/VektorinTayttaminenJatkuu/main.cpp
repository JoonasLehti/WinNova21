#include <iostream>
#include <vector>
#include <random>
using namespace std;

int main() {
    vector<int> numbers;
    numbers.resize(100000000000);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    for (long long i = 0; i < 1000000000000; ++i) {
        int random_number = dis(gen);
        numbers[i] = random_number;
    }
}
