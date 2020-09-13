#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD  = 1e9 + 7;
int main(){

    int N;
    ll num[2010];
    cin >> N;

    num[0] = 0;
    num[1] = 0;
    num[2] = 0;
    num[3] = 1;
    num[4] = 1;
    num[5] = 1;
    for (int i = 6; i <= N; ++i){

        ll sum = 1;
        for (int j = 3; j <= i-3; ++j){
            sum = (sum + num[i-j]) % MOD;
        }
        num[i] = sum;
    }
    cout << num[N] << endl;
}
