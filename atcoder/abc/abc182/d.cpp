#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    ll a, addr = 0, sum = 0, len = 0, res = 0;
    for (int i = 0; i < N; ++i){
        cin >> a;
        sum += a;
        addr += sum;
        res = max(res, addr + len);
        len = max(len, sum);
    }
    cout << res << endl;
    return 0;
}
