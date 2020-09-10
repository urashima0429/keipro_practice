#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
    int N, M, K, A[200010], B[200010];
	cin >> N >> M >> K;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i){
        cin >> B[i];
    }

    int sum = 0, i = 0, j = 0;
    while (i < N && sum + A[i] <= K){
        sum += A[i++];
    }
    while (j < M && sum + B[j] <= K){
        sum += B[j++];
    }


    int ans = i + j;
    while (i > 0){
        sum -= A[--i];

        while (j < M && sum + B[j] <= K){
            sum += B[j++];
        }
        ans = max(ans, i+j);
    }

    cout << ans << endl;
	return 0;
}