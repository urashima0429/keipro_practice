#include <iostream>
#include <algorithm>
using namespace std;

int N, M, X[100000], d[100000], sum = 0;

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i){
      	cin >> X[i];
    }
    sort(X, X+M);
    for (int i = 0; i < M - 1; ++i){
        d[i] = X[i+1] - X[i];
        sum += X[i+1] - X[i];
    }

    sort(d, d+M-1, greater<>());
    for (int i = 0; i < N - 1; ++i){
        sum -= d[i];
    }

    cout << sum << endl;
}
