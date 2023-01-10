#include <iostream>

using namespace std;

int main()
{
    int vuosi;

    cout << "Anna vuosiluku: " << endl;
    cin >> vuosi;

    if ((vuosi % 4 == 0 && vuosi % 100 != 0) || vuosi % 400 == 0)
    {
        cout << "karkausvuosi" << endl;
    }
    else
    {
        cout << "Ei ole karkausvuosi" << endl;
    }
}
