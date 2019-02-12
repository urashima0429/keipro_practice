#include <iostream>
using namespace std;

int main() {

    //initialize
    int N;
    int K;
    int A[100000];

    // input
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long f[K];
    for (int i = 0; i < K; ++i){
        for (int j = 0; j < N; ++j){
            f[i] += i ^ A[j];
        }
    }

    int f_max = 0;
    for (int i = 0; i < K; ++i){
        if (f_max < f[i]){
            f_max = f[i];
        }
    }

    cout << f_max << endl;
}