#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    const int INF = 1e9;
    const int MAX_N = 1e5 + 10;
    int N, A[MAX_N], B[MAX_N], C[MAX_N];
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
        B[i] = 0;
        C[i] = 0;
    }
    for (int i = 0; i < N; ++i){
        int b;
        cin >> b;
        B[b]++;
    }

    int num = INF;
    for (int i = 0; i < N; ++i){
        num = min(num, B[A[i]]/++C[A[i]]);
        cout << num << endl;
    }
    return 0;
}