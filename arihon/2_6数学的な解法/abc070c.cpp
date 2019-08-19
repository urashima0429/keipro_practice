#include <iostream>
using namespace std;

long long gcd(long long a, long long b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int N;
    long long p, n;
    cin >> N;

    cin >> p;
    for (int i = 1; i < N; ++i){
        cin >> n;
        long long g = gcd(p, n);
        p = p / g * n; 
    }
    cout << p << endl;
}