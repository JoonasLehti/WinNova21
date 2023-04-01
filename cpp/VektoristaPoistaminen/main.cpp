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

  vec.erase(vec.begin() + 123456, vec.begin() + 123458 + 1);

  cout << "Vektorin koko: " << vec.size() << '\n';
  for (int i = 123450; i <= 123460; ++i) {
    cout << vec[i] << ' ';
  }
}
