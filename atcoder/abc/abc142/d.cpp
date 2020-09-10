#include <iostream>
#include <string>
using namespace std;
typedef long long ll;


int main(){
    int N, K;
    string S;
    cin >> N >> K >> S;

    int dif = 0, ans = 0;
    for (int i = 0; i < N-1; ++i){
    	if (S[i] != S[i+1]) dif++;
    	else ans++;
    }
    cout << ans + min(dif, 2*K) << endl;
    return 0;
}