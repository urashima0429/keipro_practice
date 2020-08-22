#include <iostream>
using namespace std;

int main() {
	int ans = 0;
    string S, T;
    cin >> S >> T;
    for(int i = 0; i < 3; ++i){
    	if (S[i] == T[i]) ans++;
    }
    cout << ans << endl;
}