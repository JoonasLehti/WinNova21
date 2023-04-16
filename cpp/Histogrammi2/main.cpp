#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
#include <limits>
using namespace std;

int main() {
    mt19937 generator{ 42 };
    uniform_int_distribution<int> lottery{ numeric_limits<int>::min(), numeric_limits<int>::max() };
    vector<int> numbers;

    for (int i = 0; i < 10000000; ++i)
    {
        numbers.push_back(lottery(generator));
    }

    unordered_map<int, int> histogram;
    for (int number : numbers)
    {
        ++histogram[number];
    }
    for (const auto& [number, count] : histogram)
    {
        if (count >= 3) {
            cout << number << " appears " << count << " times\n";
        }
    }
}
