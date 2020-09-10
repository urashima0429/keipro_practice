#include <iostream>
using namespace std;

int main() {
    int N, M, L[30 + 1], K[30 + 1], A[30 + 1][30 + 1];
    cin >> N >> M;
    for (int i = 0; i < M + 1; ++i){
    	L[i] = 0;
    }
    for (int i = 0; i < N; ++i){
    	cin >> K[i];
    	for (int j = 0; j < K[i]; ++j){
    		cin >> A[i][j];
    		++L[A[i][j]];
    	}
    }

    int ans = 0;
    for (int i = 0; i < M + 1; ++i){
    	if (L[i] == N) ++ans;
    }

	cout << ans << endl;
}