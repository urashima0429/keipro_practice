#include <iostream>
using namespace std;

// DP 最長増加部分列 O(NlogN)

const int MAX_N = 1000, MAX_M = 1000;
int n, m, M;
int dp[MAX_N + 10][MAX_M + 10];

// 4 3 10000
// =>
// 4


int main(){

    // input
    cin >> n >> m >> M;
    for (int i = 1; i <= m; ++i){
        for (int j = 0; j <= n; ++j){
            // why...?
            dp[i][j] = 1;
        }
    }
    for (int i = 2; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            if (j - i >= 0) {
                dp[i][j] = dp[i-1][j]+ dp[i][j-i] % M;
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[m][n] << endl;
}