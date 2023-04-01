#include <iostream>
#include <set>
#include <random>
#include <limits>
#include <chrono>
using namespace std;

int main() {
    mt19937 generator{ 42 };
    uniform_int_distribution<int> lottery{ numeric_limits<int>::min(), numeric_limits<int>::max() };
    multiset<int> s;
    for (int i = 0; i < 10000000; ++i) {
        s.insert(lottery(generator));
    }
    auto start = chrono::steady_clock::now();
    cout << "Luku:  -1245214370: " << s.count(-1245214370) << '\n';
    cout << "Luku:  -164242: " << s.count(-164242) << '\n';
    cout << "Luku:  164242: " << s.count(164242) << '\n';
    cout << "Luku:  826750389: " << s.count(826750389) << '\n';
    auto end = chrono::steady_clock::now();
    cout << "Aikaa kului: " << chrono::duration_cast<chrono::microseconds>(end - start).count();
}
