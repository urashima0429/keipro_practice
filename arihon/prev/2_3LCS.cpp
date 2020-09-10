#include <iostream>
#include <string>
using namespace std;

int N, M;
string s, t;
int dp[3000][3000];



int main(){

    // input
    cin >> s >> t;
    N = s.length();
    M = t.length();
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            if (s[i] == t[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    cout << dp[N][M] << endl;
}