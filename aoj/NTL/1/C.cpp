#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b){
    int g = gcd(a, b);
    return g * (a/g) * (b/g);
}

int main(){
    int N, a, res = 1;
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> a;
        res = lcm(res, a);
    }
    cout << res << endl;
}