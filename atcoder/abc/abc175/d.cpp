#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	int N, K, P[5010], C[5010];
	cin >> N >> K;
    for (int i = 0; i < N; ++i){
        cin >> P[i];
    }
    for (int i = 0; i < N; ++i){
        cin >> C[i];
    }

    ll sum = 0;
    for (int i = 0; i < N; ++i){
        sum += C[i];
    }

    ll ans = 0;
    ans += sum * ((K-1) / N);
    

    ll M = -9e18;
    for (int i = 0; i < N; ++i){
        ll score = 0;
        int index = i;
        for (int j = 0; j < (K-1) % N + 1; ++j){
            index = P[index]-1;
            score += C[index];
            M = max(M, score);
        }
    }

    if (ans >= 0){
        cout << ans + M << endl;
    }else{
        cout <<  M << endl;    
    }

	return 0;
}