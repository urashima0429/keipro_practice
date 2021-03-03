#include <iostream>
using namespace std;
typedef long long ll;

ll nCk(int n, int k){
    if (n < 0 || k < 0 || n < k) return 0;
    k = min(k, n-k);

    ll res = 1;
    for (int i = 1; i <= k; ++i){
        res = res * (n - k + i) / i; 
    }
    return res;
}

int main(){
    int L;
    cin >> L;
    
    cout << nCk(L-1, 11) << endl;
    return 0;
}
