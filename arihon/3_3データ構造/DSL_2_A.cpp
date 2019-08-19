#include <iostream>
#include <vector>
using namespace std;

const int INF = 2147483647;
const int MAX_N = 1e6 + 10;
int N, dat[MAX_N * 2 - 1];

void init(int _n){
    N = 1;
    while( N < _n){
        N *= 2;
    }
    for (int i = 0; i < 2 * N - 1; ++i){
        dat[i] = INF;
    }
}

void update(int k, int a){
    k += N-1;
    dat[k] = a;
    while(k > 0){
        k = (k - 1) / 2;
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}

int _query(int a, int b, int k, int l, int r){
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return dat[k];
    int vl = _query(a, b, k * 2 + 1, l, (l + r)/2);
    int vr = _query(a, b, k * 2 + 2, (l + r)/2, r);
    return min(vl, vr);
}

int query(int a, int b){
    return _query(a, b, 0, 0, N);
}


int main(){
    int _N, Q;
    cin >> _N >> Q;
    init(_N);

    for (int i = 0; i < Q; ++i){
        int q, s, t;
        cin >> q >> s >> t;
        if (q == 0){
            update(s, t);
        }else{
            cout << query(s, t+1) << endl;
        }
    }
    return 0;
}