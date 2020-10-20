#include <iostream> 
using namespace std;
typedef long long ll;

int main() {
    ll N, X, M;
    int A[100010];
    cin >> N >> X >> M;
    for (int i = 0; i < M; ++i) A[i] = -1;


    int runup = 0, round = 0, offset = 0;
    ll t = X;
    for (int i = 0; i < M; ++i){
        if (A[t] != -1) {
            runup = A[t];
            round = i - runup;
            offset = (N - runup) % round;
            break;
        }
        A[t] = i;
        t = t*t % M;
    }

    ll res = 0;
    t = X;
    for (int i = 0; i < runup; ++i){
        res += t;
        t = t*t % M;
    }

    ll t2 = t;
    ll circuit = 0;
    for (int i = 0; i < round; ++i){
        circuit += t;
        t = t*t % M;
    }
    res += circuit * ((N-runup) / round);

    t = t2;
    for (int i = 0; i < offset; ++i){
        res += t;
        t = t*t % M;
    }

    cout << res << endl;

    
    return 0;
}