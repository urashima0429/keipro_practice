#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int N, K, p[1010];
    cin >> N >> K;
    for (int i = 0; i < N; ++i){
        cin >> p[i];
    }
    sort(p, p+N);

    int res = 0;
    for (int i = 0; i < K; ++i){
        res += p[i];
    }
    cout << res << endl;
	return 0;
}