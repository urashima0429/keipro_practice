#include <iostream>
using namespace std;

// DP 最長増加部分列 O(NlogN)

const int MAX_N = 1000, MAX_M = 1000;
int n, m, a[MAX_N], M;
int dp[MAX_N + 10][MAX_M + 10];

// 3 3 1 2 3 10000
// =>
// 6


int main(){

    // input
    cin >> n >> m;
    a[0] = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    cin >> M;
    for (int i = 0; i <= m; ++i){
        for (int j = 0; j <= n; ++j){
            if (j == 0) dp[i][j] = 1;
            else dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            if (j - 1 - a[i] >= 0) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j - 1 - a[i]];
            }else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    cout << dp[m][n] % M << endl;
}