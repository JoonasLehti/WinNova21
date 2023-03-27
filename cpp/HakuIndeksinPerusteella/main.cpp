#include <iostream>
#include <random>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    mt19937 generator{ 42 };
    uniform_int_distribution<int> distribution{ numeric_limits<int>::min(), numeric_limits<int>::max() };
    vector<int> numbers;

    for (int i = 0; i < 1000000; ++i) {
        numbers.push_back(distribution(generator));
    }
    cout << "+------------+" << '\n';
    for (int i = 123456; i <= 123460; ++i) {
        cout << "| " << setw(10) << numbers[i] << " |" << '\n';
    }
    cout << "+------------+" << '\n';
}
