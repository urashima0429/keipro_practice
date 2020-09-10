#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    const int H_MAX = 1010, MOD = 1e9+7;
    int H, W, dp[H_MAX][H_MAX];
    string map[H_MAX];

	cin >> H >> W;
    for (int i = 0; i < H; ++i){
        cin >> map[i];
    }
    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            if (i == 0 && j == 0){
                dp[i][j] = 1;
            } else if (map[i][j] == '#'){
                dp[i][j] = 0;
            } else {
                int res = 0;
                if (i >= 1 && dp[i-1][j] != -1){
                    res = (res + dp[i-1][j]) % MOD;
                }
                if (j >= 1 && dp[i][j-1] != -1){
                    res = (res + dp[i][j-1]) % MOD ;
                }
                dp[i][j] = res;
            }
        }
    }

    cout << dp[H-1][W-1] << endl;
	return 0;
}