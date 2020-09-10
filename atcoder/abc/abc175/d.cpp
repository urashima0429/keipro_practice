#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	int N, K, P[5010];
    ll C[5010]; 
	cin >> N >> K;
    for (int i = 0; i < N; ++i){
        cin >> P[i];
    }
    for (int i = 0; i < N; ++i){
        cin >> C[i];
    }

    ll ans = -1e18;
    for (int i = 0; i < N; ++i){
        int address = i, roop_size = -1;
        ll score[5010];
        score[0] = 0;
        for (int j = 1; j <= N; ++j){
            address = P[address]-1;
            score[j] = score[j-1] + C[address];
            if (address == i && roop_size == -1){
                roop_size = j;
            }
        }

        if (K < roop_size){
            for (int i = 1; i <= K; ++i) {
                ans = max(ans, score[i]);
            }
        } else {
            if (score[roop_size] >= 0){
                for (int i = 0; i < roop_size; ++i) {
                    ans = max(ans, score[roop_size] * ((K-i)/roop_size) + score[(K-i)%roop_size]);
                }
            }else{
                for (int i = 1; i <= roop_size; ++i) {
                    ans = max(ans, score[i]);
                }
            }
        }
    }

    cout << ans << endl;
	return 0;
}