#include <iostream>
using namespace std;

int main() {
    char a, b;
    cin >> a;
    if (a == 'A') b = 'T';
    else if (a == 'T') b = 'A';
    else if (a == 'G') b = 'C';
    else if (a == 'C') b = 'G';
    cout << b << endl;
}