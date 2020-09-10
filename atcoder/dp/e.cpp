#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	const ll INF = 4e18, V_MAX = 100010;
	ll dp[2][V_MAX];
	int N, W, w[110], v[110];
	cin >> N >> W;
	for (int i = 1; i <= N; ++i){
		cin >> w[i] >> v[i];
	}

	for (int j = 0; j < V_MAX; ++j){
		dp[0][j] = INF;
		dp[1][j] = INF;
	}

	dp[0][0] = 0LL;
	for (int i = 1; i <= N; ++i){
		for (int j = 0; j < V_MAX; ++j){
			if (j-v[i] < 0){ 
                dp[i%2][j] = dp[(i-1)%2][j];
            } else {
                dp[i%2][j] = min(dp[(i-1)%2][j], dp[(i-1)%2][j-v[i]] + w[i]);
            }
		}
	}

	int ans = 0;
	for (int j = 0; j < V_MAX; ++j){
		if (dp[N%2][j] <= W) ans = j;
	}
	cout << ans << endl;
	return 0;
}