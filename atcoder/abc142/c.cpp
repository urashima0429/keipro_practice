#include <iostream>
using namespace std;

int main(){
    int N, K, Q, A[100010];
    cin >> N >> K >> Q;
    for (int i = 0; i < Q; ++i){
        int a;
        cin >> a;
        A[a-1]++;
    }

    for (int i = 0; i < N; ++i){
        cout << (K - Q + A[i] > 0 ? "Yes" : "No" ) << endl;
    }
    return 0;
}