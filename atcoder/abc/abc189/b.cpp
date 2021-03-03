#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int N, X, res = 0, ans = -1;
    cin >> N >> X;
    for (int i = 0; i < N; ++i){
        int v, p;
        cin >> v >> p;

        res += v*p;
        if (res > X * 100){
            ans = i+1;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
