#include <iostream>
using namespace std;

int main() {
    int N, A[30], B[30], C[30];
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
   	for (int i = 0; i < N-1; ++i) cin >> C[i];

   	int ans = 0;
    for (int i = 0; i < N; ++i) ans += B[i];
    for (int i = 0; i < N-1; ++i) {
    	if(A[i]+1 == A[i+1]) ans += C[A[i]-1];
    }	
	cout << ans << endl;
	return 0;
}