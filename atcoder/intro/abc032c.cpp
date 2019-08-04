#include <iostream>
using namespace std;

int main() {
    const int MAX_N = 1e5 + 10;
    int N, K, S[MAX_N];
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> S[i];
    
    for (int i = 0; i < N; ++i){
        if (S[i] == 0) {
            cout << N << endl;
            return 0;
        }
    }

    int ans = 0;
    int product = 1;
    int l = 0;
    int r = 0;
    while (r < N){
        product *= S[r++];
        while (product > K && l < r){
            product /= S[l++];
        }
        ans = max(ans, r-l);
    }
    cout << ans << endl;
    return 0;
}