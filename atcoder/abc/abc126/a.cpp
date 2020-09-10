#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    string a = S.substr(0, K-1);
    string b = string() + (char)(S[K-1] + 32);
    string c = S.substr(K, S.length()) ;
    cout << a + b + c << endl;
}