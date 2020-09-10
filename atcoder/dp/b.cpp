#include <iostream>
using namespace std;
int iabs(int i) { return i > 0 ? i : -i; }

int main() {
	int N, K, H[100010], dp[100010];
	cin >> N >> K;
    for (int i = 0; i < N; ++i){
        cin >> H[i];
        dp[i] = 1e9;
    }

    dp[0] = 0;
    for (int i = 1; i < N; ++i){
        for (int j = max(0, i-K); j < i; ++j){
            dp[i] = min(dp[i], dp[j] + iabs(H[i]-H[j]));
        }
    }

    cout << dp[N-1] << endl;
	return 0;
}