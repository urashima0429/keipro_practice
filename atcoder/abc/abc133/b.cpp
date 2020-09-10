#include <iostream>
#include <cmath>
using namespace std;
 
 
int main() {
    const int MAX_N = 20;
    const int MAX_D = 20;
	int N, D, p[MAX_N][MAX_D];
    cin >> N >> D;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < D; ++j){
            cin >> p[i][j];
        }
    }
 
    int ans = 0;
    for (int i = 0; i < N - 1; ++i){
        for (int j = i+1; j < N; ++j){
            int dis = 0;
            for (int k = 0; k < D; ++k){
                int a = p[i][k];
                int b = p[j][k];
                dis += (a-b)*(a-b);
            }
            int c = (int) sqrt( (float)dis );
            if ( dis == c*c ) ans++;
        }
    }
 
    cout << ans << endl;
}