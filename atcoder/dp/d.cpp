#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int N, W, w[110], v[110];
    ll dp[2][100010];
	cin >> N >> W;
    for (int i = 1; i <= N; ++i){
        cin >> w[i] >> v[i];
    }

    
    for (int i = 0; i <= N; ++i){
        for (int j = 0; j <= W; ++j){
            if (i == 0) dp[i][j] = 0;

            else if (j-w[i] < 0){ 
                dp[i%2][j] = dp[(i-1)%2][j];
            } else {
                dp[i%2][j] = max(dp[(i-1)%2][j], dp[(i-1)%2][j-w[i]] + v[i]);
            }
        }
    }

    cout << dp[N%2][W] << endl;
	return 0;
}