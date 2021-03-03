#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int H, W, MOD = 1e9+7;
ll dp[2000][2000];
ll sum0[2000][2000];
ll sum1[2000][2000];
ll sum2[2000][2000];
string S[2000];

int main() {

    cin >> H >> W;
    for (int i = 0; i < H; ++i){
        cin >> S[i];
    }


    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            if (i == 0 && j == 0){
                dp[0][0] = 1;
                sum0[0][0] = 0;
                sum1[0][0] = 0;
                sum2[0][0] = 0;
                continue;
            }

            if (S[i][j] == '#'){
                dp[i][j] = 0;
                sum0[i][j] = 0;
                sum1[i][j] = 0;
                sum2[i][j] = 0;
            } else {
                if (j-1 >= 0){
                    sum0[i][j] = (dp[i][j-1] + sum0[i][j-1]) % MOD;
                }
                if (j-1 >= 0 && i-1 >= 0){
                    sum1[i][j] = (dp[i-1][j-1] + sum1[i-1][j-1]) % MOD;
                }
                if (i-1 >= 0){
                    sum2[i][j] = (dp[i-1][j] + sum2[i-1][j]) % MOD;
                }
                dp[i][j] = (dp[i][j] + sum0[i][j]) % MOD;
                dp[i][j] = (dp[i][j] + sum1[i][j]) % MOD;
                dp[i][j] = (dp[i][j] + sum2[i][j]) % MOD;
            }
        }
    }

    cout << dp[H-1][W-1] << endl;
    return 0;
}