#include <iostream>
using namespace std;

int main() {
	const int MAX_N = 100 + 10;
	const int MAX_W = 10000 + 10;
    int N, W, v[MAX_N], w[MAX_N], dp[MAX_N][MAX_W];
    cin >> N >> W;
    for (int i = 1; i <= N; ++i){
    	cin >> v[i] >> w[i];
    }

    for (int j = 0; j <= W; ++j){
    	dp[0][j] = 0;
    }

    for (int i = 1; i <= N; ++i){
    	for (int j = 0; j <= W; ++j){
    		if (j - w[i] < 0) dp[i][j] = dp[i-1][j]; 
    		else dp[i][j] = max(dp[i-1][j], dp[i][j-w[i]] + v[i]);
    	}
    }

    cout << dp[N][W] << endl;


}