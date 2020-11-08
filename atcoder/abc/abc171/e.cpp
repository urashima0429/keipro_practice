#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int N, A[200010], sum = 0;
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
        sum ^= A[i];
    }

    for (int i = 0; i < N; ++i){
        cout << (sum ^ A[i]) << endl;
    }

    return 0;
}