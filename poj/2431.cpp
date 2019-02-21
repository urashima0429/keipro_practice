#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 10000;

// 4
// 4 4 
// 5 2 
// 11 5 
// 15 10
// 25 10

// 2

void solve() {

    int N, A[MAX_N], B[MAX_N], L, P;

    // input
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin  >> A[N-1-i] >> B[N-1-i];
    }
    cin >> L >> P;
    for (int i = 0; i < N; ++i) {
        A[i] =  L - A[i];
    }

    A[N] = L;
    B[N] = 0;
    N++;

    priority_queue<int> pq;
    int res = 0, pos = 0, tank = P;

    for (int i = 0; i < N; ++i) {
        int d = A[i]-pos;

        while (d > tank) {
            if(pq.empty()){
                cout << -1 << endl;
                return;
            }else{
                res++;
                tank += pq.top();
                pq.pop();
            }
        }
        tank -= d;
        pq.push(B[i]);    
        pos = A[i];
    }

    cout << res << endl;
    return;
}

int main(){
    solve();
}