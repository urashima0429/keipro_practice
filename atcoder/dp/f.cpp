#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	string S, T;
    const int S_MAX = 3010;
    int dp[S_MAX][S_MAX];
	cin >> S >> T;

    for (int i = 0; i < S_MAX; ++i){
        for (int j = 0; j < S_MAX; ++j){
            dp[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= S.length(); ++i){
        for (int j = 1; j <= T.length(); ++j){
            if (S[i-1] == T[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string ans = "";
    int i = S.length();
    int j = T.length();
    int k = dp[i][j];
    while (dp[i][j] != 0){
        if (S[i-1] == T[j-1]){
            ans += S[i-1];
            i--;
            j--;
        } else if (dp[i][j] == dp[i][j-1]){
            j--;
        } else if (dp[i][j] == dp[i-1][j]){
            i--;
        } else {
            cout << "error" << endl;
            break;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
	return 0;
}