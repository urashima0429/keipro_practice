#include <iostream>
#include <algorithm>
using namespace std;

int N, K, h[100000];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i){
      	cin >> h[i];
    }
    sort(h, h + N);

    int ans = 1e9 + 10;
    for (int i = 0; i < N - K + 1; ++i){
    	ans = min(ans, h[i+K-1] - h[i]);
    }
    cout << ans << endl;
}