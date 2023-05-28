#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    do {
        if (arr[0] + arr[1] + arr[2] == 17 && // line from 1 to 3
            arr[0] + arr[3] + arr[6] == 17 && // line from 1 to 7
            arr[6] + arr[7] + arr[8] == 17 && // line from 7 to 9
            arr[2] + arr[5] + arr[8] == 17 && // line from 3 to 9
            arr[6] + arr[4] + arr[2] == 17) { // line from 7 to 3
            for (int i = 0; i < 9; i++) {
                cout << arr[i] << " ";
                if (i % 3 == 2) cout << endl;
            }
            break;
        }
    } while (next_permutation(arr, arr + 9));
    return 0;
}
