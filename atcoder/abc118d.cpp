#include <iostream>
using namespace std;

// todo

int N, M, A[10], B[10];
int dp[10][10000];

int main() {
    B[0] = 100000000;
    B[1] = 2;
    B[2] = 5;
    B[3] = 5;
    B[4] = 4;
    B[5] = 5;
    B[6] = 6;
    B[7] = 3;
    B[8] = 7;
    B[9] = 6;
    cin >> N >> M;
    for (int i = 0; i < M; ++i){
    	cin >> A[i];
    }

    for (int i = 0; i < M; ++i){
        for (int j = 0; j <= N; ++j){
            if (j < B[A[i]]) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = max(dp[i][j], dp[i+1][j-B[A[i]]]+1);
        }
    }



    cout << dp[M][N] << endl;

}