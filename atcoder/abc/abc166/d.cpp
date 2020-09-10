#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    const int MAX_N = 2e5+10;
    ll N, K;
    int A[MAX_N], B[MAX_N];

    cin >> N >> K;
    for (int i = 0; i < N; ++i){
        int a;
        cin >> a;
        A[i] = a-1;
        B[i] = -1;
    }

    B[0] = 0;
    int v = 0, cost = 0;
    while(B[A[v]] == -1){
        B[A[v]] = ++cost;
        v = A[v];
    }

    int offset = B[A[v]];
    int mod = ++cost - offset;

    int step = K <= offset ? K : (K - offset) % mod + offset;

    int res = 0;
    for (int i = 0; i < step; ++i){
        res = A[res];
    }
    cout << res+1 << endl;

    return 0;
}