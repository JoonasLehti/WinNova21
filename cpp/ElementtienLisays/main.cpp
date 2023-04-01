#include <iostream>
#include <vector>
#include <random>
#include <limits>
using namespace std;

int main() {
  mt19937 generator{ 42 };
  uniform_int_distribution<int> distribution{ numeric_limits<int>::min(), numeric_limits<int>::max() };

  vector<int> vec;
  for (int i = 0; i < 1000000; ++i) {
    vec.push_back(distribution(generator));
  }

  vec.insert(vec.begin() + 500000, {99, 98, 97, 96, 95});

  for (int i = 499990; i <= 500010; ++i) {
    cout << vec[i] << ' ';
  }
}
