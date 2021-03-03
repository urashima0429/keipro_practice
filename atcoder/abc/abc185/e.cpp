#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int N, M, A[1010], B[1010], dp[1010][1010];
    cin >> N >> M;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i){
        cin >> B[i];
    }
    for (int i = 0; i <= N; ++i){
        for (int j = 0; j <= M; ++j){
            if (i == 0){
                dp[i][j] = j;
            }else if(j == 0){
                dp[i][j] = i;
            }else{
                if(A[i-1] == B[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1));
                }
            }
            // cout << dp[i][j];
        }
        // cout << endl;
    }

    cout << dp[N][M]  << endl;
    return 0;
}
