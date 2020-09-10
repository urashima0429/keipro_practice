#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

// DP 個数制限なしナップザック O(NW)

const int MAX_N = 200, MAX_W = 1000;
int N, W, v[MAX_N + 1], w[MAX_N + 1];
int dp[MAX_N + 1][MAX_W + 1];

int main(){

    // input
    cin >> N >> W;
    for (int i = 0; i < N; ++i){
        cin >> v[i] >> w[i];
    }
    for (int i = 0; i <= N; ++i){
        for (int j = 0; j <= W; ++j){
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < N; ++i){
        for (int j = 0; j <= W; ++j){
            if (j < w[i]) dp[i+1][j] = dp[i][j];
            else          dp[i+1][j] = max(dp[i][j], dp[i+1][j-w[i]]+v[i]);
        }
    }

    cout << dp[N][W] << endl;
}