#include <iostream>
using namespace std;

int main() {
    const int INF = 1e9;
	const int MAX_N = 100 + 10;
	const int MAX_V = 10000 + 10;
    int N, W, v[MAX_N], w[MAX_N], dp[MAX_N][MAX_V];
    cin >> N >> W;
    int sum = 0;
    for (int i = 1; i <= N; ++i){
    	cin >> v[i] >> w[i];
        sum += v[i];
    }

    dp[0][0] = 0;
    for (int j = 1; j <= sum; ++j){
    	dp[0][j] = INF;
    }

    for (int i = 1; i <= N; ++i){
    	for (int j = 0; j <= sum; ++j){
            // cout << i << ":" << j << endl;
    		if (j-v[i] < 0) dp[i][j] = dp[i-1][j];
    		else dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);
    	}
    }

    int ans = 0;
    for (int j = 0; j <= sum; ++j){
        if (dp[N][j] <= W) ans = j;
    }
    cout << ans << endl;


}