#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int N, M, K, A[100], B[100], C[20], D[20], res = 0;
    cin >> N >> M;
    for (int i = 0; i < M; ++i){
        cin >> A[i] >> B[i];
    }
    cin >> K;
    for (int i = 0; i < K; ++i){
        cin >> C[i] >> D[i];
    }

    for (int i = 0; i < (1<<K); ++i){
        bool sat[110];
        for (int j = 0; j < N; ++j){
            sat[j] = false;
        }
        for (int j = 0; j < K; ++j){
            if (i & (1<<j)){
                sat[D[j]-1] = true;
            }else{
                sat[C[j]-1] = true;
            }

        }

        int sum = 0;
        for (int j = 0; j < M; ++j){
            if (sat[A[j]-1] && sat[B[j]-1]) sum++;
        }
        res = max(res, sum);
    }

    cout << res << endl;
}
