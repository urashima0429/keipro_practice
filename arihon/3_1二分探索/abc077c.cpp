#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    const int MAX_N = 1e5+10;
    int N, AB[MAX_N], BC[MAX_N];
    vector<int> A, B, C;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        B.push_back(a);
    }
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        C.push_back(a);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    int sum = 0;
    for (int i = 0; i < N; ++i){
        sum += lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        AB[i] = sum;
    }
    for (int i = 0; i < N; ++i){
        BC[i] = lower_bound(B.begin(), B.end(), C[i]) - B.begin();
    }

    long long ans = 0;
    for(int i = 0; i < N; ++i){
        if (0 <= BC[i]-1) ans += AB[BC[i]-1];
    }
    cout << ans << endl;
}