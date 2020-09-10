#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(){
    int N, A[200010], B[200010];
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> A[i] >> B[i];
    }
    sort(A, A+N);
    sort(B, B+N);

    if ( N % 2 == 1){
        cout << B[N/2] - A[N/2] + 1 << endl;
    } else {
        cout << B[N/2-1] + B[N/2] - A[N/2-1] - A[N/2] << endl;
    }

    return 0;
}