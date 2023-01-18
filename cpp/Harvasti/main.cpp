#include <iostream>
#include <string>

using namespace std;

int main()
{
    string nimi;
    cout << "Anna Nimi: ";
    getline(cin, nimi);

    for (size_t i = 0; i < nimi.length(); i++)
    {
        cout << nimi[i] << " ";
    }

    return 0;
}
