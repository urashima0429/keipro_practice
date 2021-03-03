#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int N, A[100010], B[100010];
    ll res = 0;
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i){
        cin >> B[i];
    }
    for (int i = 0; i < N; ++i){
        res += A[i]*B[i];
    }
    cout << (res == 0 ? "Yes" : "No") << endl;
    return 0;
}
