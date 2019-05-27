#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int multi_gcd(int *a, int n){
    if (n == 1){
        return a[0];
    }else if(n == 2){
        return gcd(a[0], a[1]);
    }else{
        int l_size = n/2;
        int r_size = n - l_size;
        return gcd(
            multi_gcd(a, l_size), 
            multi_gcd(a + l_size, r_size)
        );
    }
}

int main(){
    const int MAX_N = 1e5;
    int N, A[MAX_N];
    cin >> N;
        for (int i = 0; i < N; ++i){
        cin >> A[i];
    }

    int l[MAX_N], r[MAX_N]; 
    l[0] = A[0];
    for (int i = 0; i < N-1; ++i){
        l[i+1] = gcd(l[i], A[i+1]);
    }
    r[0] = A[N-1];
    for (int i = 0; i < N-1; ++i){
        r[i+1] = gcd(r[i], A[N-i-2]);
    }
    int ans = 1;
    for (int i = 0; i < N; ++i){
        ans = max(ans, gcd(l[i], r[N-i-1]));
    }

    cout << ans << endl;
}