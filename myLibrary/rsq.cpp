#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 区間和を求める(Binary indexed treeによる)
// sum(int i)        : O(log(n)) : 区間(1 < x <= i)の和を求める
// add(int i, int x) : O(log(n)) : iにx足す

const int MAX_N = 1e5 + 10;
int N, bit[MAX_N + 10];

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




































