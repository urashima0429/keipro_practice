#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    vector<int> A, B;
    cin >> N;
    for (int i = 0; i <= N; ++i){
        int a;
        cin >> a;
        A.push_back(a);
    }

    for (int i = 0; i < N; ++i){
        int b;
        cin >> b;
        B.push_back(b);
    }

    long long ans = 0;
    for (int i = N-1; i >= 0; --i){
        int r = min(A[i+1], B[i]);
        int l = min(A[i], B[i] - r);
        ans += r+l;
        A[i] -= l;
    }
    cout << ans << endl;
    return 0;
}