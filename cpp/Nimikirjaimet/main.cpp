#include <iostream>

using namespace std;

int main()
{
    string nimi;
    cout << "Anna Nimi: ";
    getline(cin, nimi);

    size_t valilyonti = nimi.find(" ");
    cout << "Nimikirjaimesi ovat: " << nimi[0] << nimi[valilyonti+1] << endl;

    return 0;
}
