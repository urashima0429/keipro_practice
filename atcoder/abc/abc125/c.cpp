#include <iostream>
using namespace std;
typedef long long ll;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int N, A[100010], L[100010], R[100010];
    cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> A[i];
    }
    L[0] = 0;
    for (int i = 1; i <= N; ++i){
        L[i] = gcd(L[i-1], A[i]);
    }
    
    R[N+1] = 0;
    for (int i = N; i >= 1 ; --i){
        R[i] = gcd(R[i+1], A[i]);
    }
    
    int ans = 0;
    for (int i = 1; i <= N; ++i){
        ans = max(ans, gcd(L[i-1], R[i+1]));
    }
    cout << ans << endl;    
}

