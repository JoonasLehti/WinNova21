#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main() {
    ifstream file("D:\\Market_Basket_Optimisation.csv");

    vector<vector<string>> data;
    string line;
    while (getline(file, line)) {
        vector<string> row;
        string cell;
        stringstream lineStream(line);
        while (getline(lineStream, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }

    map<set<string>, int> candidates;
    for (const auto& row : data) {
        for (const auto& cell : row) {
            set<string> itemset = {cell};
            candidates[itemset]++;
        }
    }

    map<set<string>, int> frequentItemsets;
    for (const auto& candidate : candidates) {
        if (candidate.second >= 30) {
            frequentItemsets[candidate.first] = candidate.second;
        }
    }

    for (int k = 2; k <= 4; ++k) {
        candidates.clear();
        for (const auto& itemset1 : frequentItemsets) {
            for (const auto& itemset2 : frequentItemsets) {
                set<string> candidate(itemset1.first.begin(), itemset1.first.end());
                candidate.insert(itemset2.first.begin(), itemset2.first.end());
                if (candidate.size() == k) {
                    candidates[candidate] = 0;
                }
            }
        }

        for (const auto& row : data) {
            set<string> rowSet(row.begin(), row.end());
            for (auto& candidate : candidates) {
                if (includes(rowSet.begin(), rowSet.end(), candidate.first.begin(), candidate.first.end())) {
                    candidate.second++;
                }
            }
        }

        frequentItemsets.clear();
        for (const auto& candidate : candidates) {
            if (candidate.second >= 30) {
                frequentItemsets[candidate.first] = candidate.second;
            }
        }
    }

    for (const auto& itemset : frequentItemsets) {
        for (const auto& item : itemset.first) {
            cout << "'" << item << "'" << ' ';
        }
        cout << ": " << itemset.second << '\n';
    }
}
