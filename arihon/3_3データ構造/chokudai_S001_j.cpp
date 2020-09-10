#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

// 区間和を求める(Binary indexed treeによる)
// sum(int i)        : O(log(n)) : 区間(1 < x <= i)の和を求める
// add(int i, int x) : O(log(n)) : iにx足す

const int MAX_N = 2e5 + 10;
int N;
ll bit[MAX_N + 10];

ll sum (int i){
    ll s = 0;
    while(i > 0){
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add (int i, ll x){
    while(i <= N){
        bit[i] += x;
        i += i & -i;
    }
}

int main(){
    ll ans = 0;
    cin >> N;
    for (ll i = 0; i < N; ++i){
        int a;
        cin >> a;
        cout <<  i - sum(a) << endl;
        ans += i - sum(a);
        add(a, 1LL);
    }
    cout << ans << endl;
    return 0;
}
