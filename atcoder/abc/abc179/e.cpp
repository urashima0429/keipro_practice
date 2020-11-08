#include <iostream> 
using namespace std;
typedef long long ll;

int main() {
    ll N, X, M, A[100010];
    cin >> N >> X >> M;
    for (int i = 0; i < M; ++i){
        A[i] = -1;
    }

    ll sum = X;
    ll t = X;
    for (int i = 1; i <= M; ++i){
        
        cout << i  <<":" << t << endl;

        if (t == 0) {
            break;
        } else if(A[t] == -1) {
            A[t] = sum;
        } else {
            sum = A[N / i] * (N / i) + A[N % i];
            break;
        }

        t = t*t % M;
        sum += t;
    }
    
    cout << sum << endl;
    return 0;
}