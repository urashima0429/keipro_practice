#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ll N, Q, sum = 0;
    int A[100010];

    for (int i = 1; i < 100010; ++i) A[i] = 0;
    cin >> N;
    for (int i = 0; i < N; ++i){
        int t;
        cin >> t;
        A[t]++;
        sum += t;
    }


    cin >> Q;
    for (int i = 0; i < Q; ++i){
        int b, c;
        cin >> b >> c;
        sum += (c-b) * A[b];
        A[c] += A[b];
        A[b] = 0;

        cout << sum << endl;
    }

    return 0;
}