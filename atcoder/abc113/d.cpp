#include <iostream>
using namespace std;

long long fib(int k){
    if (k <= -2) return 0LL;
    if (k <= 0) return 1LL;
    return fib(k-1) + fib(k-2);
}

int main(){
    const long long MOD = 1e9+7;
    const int MAX_H = 100;
    const int MAX_W = 8;
    int H, W, K;
    long long dp[MAX_H + 10][MAX_W + 10];

    cin >> H >> W >> K;
    for (int i = 0; i <= H; ++i){
        for (int j = 1; j <= W; ++j){
            if (i == 0 && j == 1) dp[i][j] = 1LL;
            else dp[i][j] = 0LL;
        }
    }
    
    long long tmp;
    for (int i = 1; i <= H; ++i){
        for (int j = 1; j <= W; ++j){
            
            if (j - 1 >= 1){
                tmp = dp[i-1][j-1] * fib((j-2)-1) % MOD;
                tmp = tmp * fib(W-(j+1)) % MOD;
                dp[i][j] = (dp[i][j] + tmp) % MOD;
            }
            
            tmp = dp[i-1][j] * fib((j-1)-1) % MOD;
            tmp = tmp * fib(W-(j+1)) % MOD;
            dp[i][j] = (dp[i][j] + tmp) % MOD;
            
            if (j + 1 <= W){
                tmp = dp[i-1][j+1] * fib((j-1)-1) % MOD;
                tmp = tmp * fib(W-(j+2)) % MOD;
                dp[i][j] = (dp[i][j] + tmp) % MOD;
            }
        }
    }
    cout << dp[H][K] << endl;
}

