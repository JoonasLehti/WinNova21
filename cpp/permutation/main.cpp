#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<vector<int>> solutions;

    do {
        if (arr[0] + arr[1] + arr[2] == 17 && // line from 1 to 3
            arr[0] + arr[3] + arr[6] == 17 && // line from 1 to 7
            arr[6] + arr[7] + arr[8] == 17 && // line from 7 to 9
            arr[2] + arr[5] + arr[8] == 17 && // line from 3 to 9
            arr[6] + arr[4] + arr[2] == 17) { // line from 7 to 3

            vector<int> solution(arr, arr + 9);
            solutions.push_back(solution);
        }
    }
    while (next_permutation(arr, arr + 9));

    for (const auto& solution : solutions)
    {
        for (int i = 0; i < 9; i++)
        {
            cout << solution[i] << " ";
            if (i % 3 == 2) cout << endl;
        }
        cout << endl;
    }
    return 0;
}
