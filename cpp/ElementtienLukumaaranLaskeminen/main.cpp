#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

int main() {
    mt19937 generator{ 42 };
    uniform_int_distribution<int> lottery{ numeric_limits<int>::min(), numeric_limits<int>::max() };
    vector<int> vec;
    for (int i = 0; i < 10000000; ++i) {
        vec.push_back(lottery(generator));
    }
    auto start = chrono::steady_clock::now();
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    for (int value : vec) {
        if (value == -1245214370) {
            ++count1;
        } else if (value == -164242) {
            ++count2;
        } else if (value == 164242) {
            ++count3;
        } else if (value == 826750389) {
            ++count4;
        }
    }
    auto end = chrono::steady_clock::now();
    cout << "Kuinka monta lukua on -1245214370: " << count1 << '\n';
    cout << "Kuinka monta lukua on -164242: " << count2 << '\n';
    cout << "Kuinka monta lukua on 164242: " << count3 << '\n';
    cout << "Kuinka monta lukua on 826750389: " << count4 << '\n';
    cout << "Aikaa kului: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << '\n';
}
