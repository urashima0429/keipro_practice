#include <iostream>
#include <algorithm>
using namespace std;

int N, h[100 + 1];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i){
      	cin >> h[i];
    }
    h[N] = 0;

    int ans = 0;
    int p = 0;
    for (int i = 0; i < N + 1; ++i){
        if (p > h[i]) ans += p - h[i];
        p = h[i];
    }

    cout << ans << endl;
}
