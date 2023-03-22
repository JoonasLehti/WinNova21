#include <iostream>
#include <vector>
#include <random>
using namespace std;

int main() {
    vector<int> numbers;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < 1000000000; ++i) {
        int random_number = dis(gen);
        numbers.push_back(random_number);
    }
}
