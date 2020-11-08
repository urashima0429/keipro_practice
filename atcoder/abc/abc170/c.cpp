#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int abs(int a, int b){
    return a > b ? a-b : b-a;
}
int main() {
    int X, N;
    vector<bool> p(110, false);
    cin >> X >> N;
    for (int i = 1; i <= N; ++i){
        int t;
        cin >> t;
        p[t] = true;
    }

    int res = 0;
    int m = 200;
    for (int i = 0; i <= 101; ++i){
        if ( !p[i] && abs(X, i) < m){
            res = i;
            m = abs(X, i);
        }
    }
    cout << res << endl;
}