#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, M, K, A[200010], B[200010], sum = 0;
	cin >> N >> M >> K;
    A[0] = 0;
    for (int i = 1; i <= N; ++i){
        int a; 
        cin >> a;
        A[i] = A[i-1] + a;
    }
    for (int i = 0; i < M; ++i){
        cin >> B[i];
    }

    for (int i = N; i >= 0; ++i){
        
    }






    cout << ans << endl;
	return 0;
}