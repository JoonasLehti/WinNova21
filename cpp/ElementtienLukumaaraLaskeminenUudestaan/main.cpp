#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <algorithm>
#include <chrono>
using namespace std;

int main() {
  mt19937 generator{ 42 };
  uniform_int_distribution<int> lottery{ numeric_limits<int>::min(), numeric_limits<int>::max() };

  vector<int> vec;
  for (int i = 0; i < 10000000; ++i) {
    vec.push_back(lottery(generator));
  }

  sort(vec.begin(), vec.end());

  auto start = chrono::steady_clock::now();
  int numbers[] = {-1245214370, -164242, 164242, 826750389};
  for (int number : numbers) {
    auto lower = lower_bound(vec.begin(), vec.end(), number);
    auto upper = upper_bound(vec.begin(), vec.end(), number);
    cout << "Arvo " << number << " toistuu " << upper - lower << " kertaa\n";
  }
  auto end = chrono::steady_clock::now();
  cout << "Aikaa kesti: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << '\n';
}
