#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S;
    cin >> S;

    int m = 1e9;
    for (int i = 0; i < S.size() - 2; ++i){
        int x = ( S[i + 0] - '0') * 100 
              + ( S[i + 1] - '0') * 10
              + ( S[i + 2] - '0') * 1;
        m = min(m, abs(x-753));
    }
	cout << m << endl;
}