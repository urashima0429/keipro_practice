#include <iostream>
using namespace std;

int main() {
    const int MAX_N = 1e5 + 10;
    int N, A[MAX_N];
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];

    int ans = 0;
    int l = 0;
    int r = 0;
    while (r < N){
        while (r < N-1 && A[r] < A[r+1]){
            r++;
        }
        int d = r - l + 1;
        ans += d * (d + 1) / 2;
        l=++r;
    }
    cout << ans << endl;
    return 0;
}