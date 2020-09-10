#include <iostream>
using namespace std;

int main() {
    const int MAX_N = 100 + 10;
    const int MAX_P = 10000 + 10;
    int N, P = 0, p[MAX_N];
    bool dp[MAX_N][MAX_P];
    cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> p[i];
        P += p[i];
    }

    dp [0][0] = true;
    for (int j = 1; j <= P; ++j){
        dp[0][j] = false;
    }

    for (int i = 1; i <= N; ++i){
        for (int j = 0; j <= P; ++j){
            if (j - p[i] < 0) dp[i][j] = dp[i-1][j]; 
            else dp[i][j] = dp[i-1][j] || dp[i-1][j-p[i]];
        }
    }

    int ans = 0;
    for (int j = 0; j <= P; ++j){
        if (dp[N][j] == true) ans++;
    }
    cout << ans << endl;
}