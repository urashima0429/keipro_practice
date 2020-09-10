#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin >> N;

    ll a, b;
    for (ll i = 1; i*i <= N; ++i){
        if (N % i == 0) a = i;
    }
    b = N / a;
    cout << a + b - 2 << endl;

    return 0;
}