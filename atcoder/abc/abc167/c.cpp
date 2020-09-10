#include <iostream>
#include <vector>
using namespace std;

vector<int> next_comb(int n, int k, vector<int> v){
    if (n < k) cout << "error" << endl;
    for (int i = 0; i < v.size()-1; ++i) {
        if (v[i] >= v[i+1]) cout << "error" << endl;
    }

    for(int i = k-1; i >= 0; --i){
        if (v[i] != i+n-k){
            int t = ++v[i];
            for (int j = i+1; j < k; ++j){
                v[j] = ++t;
            }
            return v;
        }
    }

    for (int i = 0; i < k; ++i){
        v[i] = i;
    }
    return v;
}

int comb(int n, int k){
    if ( n < 0 || k < 0 || k > n) return 0;
    k = min(k, n-k);
    int p = 1, q = 1;
    while ( k > 0 ) {
        p *= n--;
        q *= k--;
    }
    return p / q;
}

int main(){
    const int INF = 2e9+10;
    int N, M, X, C[20], A[20][20];
    cin >> N >> M >> X;
    for (int i = 0; i < N; ++i){
        cin >> C[i];
        for (int j = 0; j < M; ++j){
            cin >> A[i][j];
        }
    }

    int res = INF; 
    for (int i = 1; i <= N; ++i){

        vector<int> v;    
        for (int j = 0; j < i; ++j){
            v.push_back(j);
        }

        for (int p = 0; p < comb(N, i); ++p){

            int c = 0;
            int a[M];
            for (int k = 0; k < M; ++k) a[k] = 0;

            for (int j : v){
                c += C[j];
                for (int k = 0; k < M; ++k){
                    a[k] += A[j][k];
                }
            }

            bool check = true;
            for (int k = 0; k < M; ++k){
                check &= a[k] >= X;
            }

            if (check) {
                res = min(res, c);
            }

            v = next_comb(N, i, v);
        }
    }

    if (res != INF){
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}