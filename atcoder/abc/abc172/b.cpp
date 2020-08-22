#include <iostream>
#include <string>
using namespace std;

int main() {
    int ans = 0;
	string S, T;
	cin >> S >> T;
    for (int i = 0; i < S.length(); ++i){
        if (S[i] != T[i]) ans++;
    }
    cout << ans << endl;
	return 0;
}