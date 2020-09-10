#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5 + 10;
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

int main(){
    int Q;
    cin >> N >> Q;
    for (int i = 0; i < Q; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0){
            add(b, c);
        }else{
            cout << sum(c) - sum(b-1) << endl;
        }
    }
    return 0;
}




































