#include <iostream>
#include <string>
using namespace std;

int main() {
    string s("2019/04/30"), t;
    cin >> t;
    cout << (s < t ? "TBD" : "Heisei") << endl;
}