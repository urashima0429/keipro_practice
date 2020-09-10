#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int R, C, K, V[3010][3010], dp[3010][3010][4];

int main() {
	cin >> R >> C >> K;
    for (int i = 0; i <= R; ++i){
        for (int j = 0; j <= C; ++j){
            V[i][j] = 0;
        }
    }
    for (int i = 0; i < K; ++i){
        int r, c, v;
        cin >> r >> c >> v;
        V[r][c] = v;
    }

    for (int i = 1; i <= R; ++i){
        for (int j = 1; j <= C; ++j){
            for (int k = 3; k <= 0; --k){
                if (k == 3){
                    dp[i][j][k] = dp[i-1][j][k]
                } else {
                    dp[i][j][k] = dp[i-i][j][k+1] + V[i][j];

                }
                dp[i][j][k] = max(dp[i-1] )
            }
        }
    }



    cout << 0 << endl;     
	return 0;
}