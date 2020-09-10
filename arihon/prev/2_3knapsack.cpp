#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

// DP 01ナップザック　O(NW)

// 3 10
// 15 9 
// 10 6
// 6 4
// 
// 16

const int MAX_N = 200, MAX_W = 1000;
int N, W, v[MAX_N + 1], w[MAX_N + 1];
int dp[MAX_N + 1][MAX_W + 1];

int rec(int i, int j){
    if (dp[i][j] >= 0){
        return dp[i][j];
    }
    int res;
    if (i == N){
        // 
        res = 0;
    }else if (j < w[i]){
        // もう入らない
        res = rec(i + 1, j);
    }else{
        res = max(
            rec(i + 1, j),
            rec(i + 1, j - w[i]) + v[i]
        );
    }
    return dp[i][j] = res;
}

int main(){

    // input
    cin >> N >> W;
    for (int i = 0; i < N; ++i){
        cin >> v[i] >> w[i];
    }
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < W + 1; ++j){
            dp[i][j] = -1;
        }
    }

    cout << rec(0, W) << endl;
}