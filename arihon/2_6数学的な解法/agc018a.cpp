#include <iostream>
using namespace std;

long long gcd(long long a, long long b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int N, K;
    long long p, n, M;
    bool b = false;
    cin >> N >> K;

    cin >> p;
    M = p;
    for (int i = 1; i < N; ++i){
        cin >> n;
        p = gcd(p, n);
        M = max(M, n);
        if (n == K) b = true;
    }

    cout << ( b||(K % p == 0 && K <= M) ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}