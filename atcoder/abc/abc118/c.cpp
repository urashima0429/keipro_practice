#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int N, A[100000];
    cin >> N;

    for (int i = 0; i < N; ++i){
    	cin >> A[i];;
    }

    for (int i = 0; i < N - 1; ++i){
        A[i+1] = gcd(A[i], A[i+1]);
    }

    cout << A[N-1] << endl;
}