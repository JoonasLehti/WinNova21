#include <iostream>
#include <set>
#include <random>
#include <limits>
using namespace std;

int main() {
    mt19937 generator{ 42 };
    uniform_int_distribution<int> lottery{ numeric_limits<int>::min(), numeric_limits<int>::max() };
    set<int> s;
    for (int i = 0; i < 10000000; ++i) {
        s.insert(lottery(generator));
    }
    auto it = s.find(-1245214370);
    if (it != s.end()) {
        cout << "Arvo: -1245214370: " << distance(s.begin(), it) + 1 << '\n';
    } else {
        cout << "Arvo: -1245214370: ei loydy\n";
    }
    it = s.find(122460941);
    if (it != s.end()) {
        cout << "Arvo: 122460941: " << distance(s.begin(), it) + 1 << '\n';
    } else {
        cout << "Arvo: 122460941: ei loydy\n";
    }
    it = s.find(-122460941);
    if (it != s.end()) {
        cout << "Arvo: -122460941: " << distance(s.begin(), it) + 1 << '\n';
    } else {
        cout << "Arvo: -122460941: ei loydy\n";
    }
    it = s.find(1385283091);
    if (it != s.end()) {
        cout << "Arvo: 1385283091: " << distance(s.begin(), it) + 1 << '\n';
    } else {
        cout << "Arvo: 1385283091: ei loydy\n";
    }
}
