#include <iostream>
using namespace std;
typedef long long ll;

ll F(ll x){
    if (x % 4 == 0) return x;
    if (x % 4 == 1) return 1;
    if (x % 4 == 2) return x+1;
    else return 0;
}

int main(){
    ll A, B;
    cin >> A >> B;
    cout << (F(B)^F(A-1)) << endl;
    return 0;
}

