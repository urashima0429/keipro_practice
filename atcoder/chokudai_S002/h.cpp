#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int main(){
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i){
        int a, b;
        cin >> a >> b;
        if (a == b) cout << -1 << endl;
        else cout << (a > b ? a-b:b-a) << endl;
    }
    return 0;
}