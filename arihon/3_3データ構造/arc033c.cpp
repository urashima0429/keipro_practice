#include <iostream>
using namespace std;

const int MAX_N = 2e5;
int N, bit[MAX_N + 10];

// 1 < x <= i
int sum (int i){
    int s = 0;
    while(i > 0){
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add (int i, int x){
    while(i <= N){
        bit[i] += x;
        i += i & -i;
    }
}

int getkth(int k){
    int l = 0, m, r = MAX_N;
    while(l + 1 < r){
        m = (l + r) / 2;
        if (sum(m) >= k){
            r = m;
        }else{
            l = m;
        }
    }
    return r;
}

int main(void){
    N = MAX_N;
    int Q, t, x;
    cin >> Q;
    for (int i = 0; i < Q; ++i){
        cin >> t >> x;
        if (t == 1){
            add(x, 1);
        }else{
            int v = getkth(x);
            cout << v << endl;
            add(v, -1);
        }
    }
    return 0;
}

