#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

int main() {
    mt19937 generator{ 42 };
    uniform_int_distribution<int> lottery{ numeric_limits<int>::min(), numeric_limits<int>::max() };
    vector<int> vec;
    for (int i = 0; i < 1000000000; ++i) {
        vec.push_back(lottery(generator));
    }
    auto start1 = chrono::steady_clock::now();
    int count1 = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec.at(i) > 0) {
            ++count1;
        }
    }
    auto end1 = chrono::steady_clock::now();
    cout << "Arvojen maara kayttaen at(): " << count1 << '\n';
    cout << "Aikaa kului: " << chrono::duration_cast<chrono::milliseconds>(end1 - start1).count() << '\n';

    auto start2 = chrono::steady_clock::now();
    int count2 = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] > 0) {
            ++count2;
        }
    }
    auto end2 = chrono::steady_clock::now();
    cout << "Arvojen maara kayttaen []: " << count2 << '\n';
    cout << "Aikaa kului: " << chrono::duration_cast<chrono::milliseconds>(end2 - start2).count() << '\n';
}
