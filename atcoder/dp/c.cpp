#include <iostream>
using namespace std;

int main() {
	int N, dp[3];
	cin >> N >> dp[0] >> dp[1] >> dp[2];
    for (int i = 1; i < N; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        a += max(dp[1], dp[2]);
        b += max(dp[2], dp[0]);
        c += max(dp[1], dp[0]);
        dp[0] = a;
        dp[1] = b;
        dp[2] = c;
    }

    cout << max(dp[0], max(dp[1], dp[2])) << endl;
	return 0;
}