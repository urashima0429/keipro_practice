#include <iostream>
#include <string>

using namespace std;

// todo

int N, M, A[10], B[10] = {100000,2,5,5,4,5,6,3,7,6};
string dp[10][10000];

int main() {

    cin >> N >> M;
    for (int i = 0; i < M; ++i){
    	cin >> A[i];
    }
    for (int i = 0; i < M; ++i){
        for (int j = 0; j <= N; ++j){
            dp[i][j] = "";   
        }
    }

    for (int i = 0; i < M; ++i){
        for (int j = 0; j <= N + 2; ++j){
            if (j < B[A[i]]) {
                dp[i+1][j] = dp[i][j];
            }else {
                string b = dp[i+1][j-B[A[i]]] + (char)('0' + A[i]);
                if (dp[i][j].size() > b.size()){
                    dp[i+1][j] = dp[i][j];
                // }else if (dp[i][j].size() == b.size()){
                //     dp[i+1][j] = max(dp[i][j], b);
                }else{
                    dp[i+1][j] = b;
                }
            }
        }
    }
    cout << dp[M][N] << endl;
}