#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int N, A[10010], res = 0;
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i){
        int m = A[i];
        for (int j = i; j < N; ++j){
            m = min(m, A[j]);
            res = max(res, m * (j-i+1));
        }
    }
    cout << res << endl;
}
