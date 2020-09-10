#include <iostream>
using namespace std;

const int MAX_N = 1e3+10; 
int D[MAX_N];

void prime_factor(int n){
    for (int i = 2; i*i <= n; ++i){
        while(n % i == 0){
            D[i]++;
            n /= i;
        }
    }
    if (n != 1) D[n] += 1; 
}


int main(){
    int N;
    int MOD = 1e9+7;
    cin >> N;
    for (int i = 2; i < N; ++i){
        D[i] = 0;
    }
    for (int i = 2; i <= N; ++i){
        prime_factor(i);
    }
    long long ans = 1;
    for (int i = 2; i <= N; ++i){
        // cout << i << ":" << D[i] << endl;
        ans = ans * (D[i] + 1) % MOD;
    }

    cout << ans << endl;
}