#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

// DP 01ナップザック O(nΣvi)  

const int MAX_N = 100, MAX_W = 1e9, MAX_SUM_VI = 1e4;
const int INF = MAX_W + 10;
int N, W, v[MAX_N + 1], w[MAX_N + 1];
int dp[MAX_N + 1][MAX_SUM_VI + 1];

int main(){

    int sum_vi = 0;
    // input
    cin >> N >> W;
    for (int i = 0; i < N; ++i){
        cin >> v[i] >> w[i];
        sum_vi += v[i];
    }

    // init 
    dp[0][0] = 0;
    for (int j = 1; j <= sum_vi; ++j){
        dp[0][j] = INF;
    }

    for (int i = 0; i < N; ++i){
        for (int j = 0; j <= sum_vi; ++j){
            if (j < v[i]) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]] + w[i]);
        }
    }

    int ans = 0;
    for (int j = 1; j <= sum_vi; ++j){
        if (dp[N][j] <= W) ans = j;
    }

    cout << ans << endl;
}