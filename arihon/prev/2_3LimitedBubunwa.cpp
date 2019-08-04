#include <iostream>
using namespace std;

// DP 個数制限付き部分和  

const int MAX_N = 1e2, MAX_K = 1e5;
int N, K, a[MAX_N + 1], m[MAX_K + 1];
int dp[MAX_N + 1][MAX_K + 1];

int main(){

    // input
    cin >> N >> K;
    for (int i = 0; i < N; ++i){
        cin >> a[i] >> m[i];
    }

    // init 
    dp[0][0] = 0;
    for (int j = 1; j <= K; ++j){
        dp[0][j] = -1;
    }

    for (int i = 0; i < N; ++i){
        for (int j = 0; j <= K; ++j){
            if (dp[i][j] >= 0) dp[i+1][j] = m[i];
            else if (j < a[i] || dp[i+1][j-a[i]] <= 0) dp[i+1][j] = -1;
            else dp[i+1][j] = dp[i+1][j-a[i]] - 1;
        }
    }
    if (dp[N][K] >= 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}