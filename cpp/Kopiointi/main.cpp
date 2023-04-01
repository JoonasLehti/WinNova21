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

  vector<int> copy(vec.begin() + 123450, vec.begin() + 123458 + 1);

  for (int i = 0; i < copy.size(); ++i) {
    cout << copy[i] << ' ';
  }
}
