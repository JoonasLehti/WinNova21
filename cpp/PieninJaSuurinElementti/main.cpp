#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <algorithm>
using namespace std;

int main() {
  mt19937 generator{ 42 };
  uniform_int_distribution<int> distribution{ numeric_limits<int>::min(), numeric_limits<int>::max() };

  vector<int> vec;
  for (int i = 0; i < 1000000; ++i) {
    vec.push_back(distribution(generator));
  }

  auto minmax = minmax_element(vec.begin(), vec.end());

  cout << "Pienin arvo: " << *minmax.first << '\n';
  cout << "Suurin arvo: " << *minmax.second << '\n';
}
