#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int N;
    vector<ll> A;
    ll res = 0;
    cin >> N;
    for (int i = 0; i < N; ++i){
        ll a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());

    ll sum = A[0];
    for (int i = 1; i < N; ++i){
        res += A[i] * i - sum;
        sum += A[i];
    }

    cout << res << endl;
    return 0;
}
