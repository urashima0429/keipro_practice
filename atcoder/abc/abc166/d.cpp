#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int X;
    cin >> X;

    for (ll a = -1000; a <= 1000; ++a){
        for (ll b = -1000; b <= 1000; ++b){
            if (a*a*a*a*a - b*b*b*b*b == X) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
    return 0;
}