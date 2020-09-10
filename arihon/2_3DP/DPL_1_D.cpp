#include <iostream>
using namespace std;

int main() {
    const int INF = 2e9;
	const int MAX_N = 1e5 + 10;
    int N, A[MAX_N];
    cin >> N;
    for (int i = 0; i < N; ++i){
        A[i] = INF;
    }

    for (int i = 0; i < N; ++i){
        int a;
        cin >> a;
        *lower_bound(A, A+N, a) = a;
    }

    cout << lower_bound(A, A+N, INF) - A <<endl;
    
}