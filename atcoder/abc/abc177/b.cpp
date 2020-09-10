#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    int m = 0;
	string S, T;
	cin >> S >> T;
    for (int i = 0; i <= S.length() - T.length(); ++i){
        
        int res = 0;
        for (int j = 0; j < T.length(); ++j){
            if (S[i+j] == T[j]) res++;
        }
        m = max(m, res);
    }

    cout << T.length() - m << endl; 
	return 0;
}