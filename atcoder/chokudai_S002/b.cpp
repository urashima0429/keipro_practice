#include <iostream>

using namespace std;

int main(){
    const int MAX_N = 1e5 + 10;
    int N;
    int A[MAX_N], B[MAX_N];
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> A[i] >> B[i];
    }

    for (int i = 0; i < N; ++i){
        cout << A[i] % B[i] << endl;
    }
    return 0;
}