#include <iostream>
using namespace std;

int main() {
	int N, H[100010], dp[100010];
	cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> H[i];
    }

    dp[0] = 0;
    dp[1] = std::abs(H[1] - H[0]);
    for (int i = 2; i < N; ++i){
        dp[i] = min(dp[i-1] + std::abs(H[i] - H[i-1]), dp[i-2] + std::abs(H[i] - H[i-2]) );
    }

    cout << dp[N-1] << endl;
	return 0;
}