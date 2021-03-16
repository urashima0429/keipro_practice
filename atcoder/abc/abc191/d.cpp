#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    ll res = 0;
    double X,Y,R, eps = 0.1;
    cin >> X >> Y >> R;

    for (int y = (int)(Y - R + 1 - eps); y <= (int)(Y + R + eps); ++y){

        double l,m,r;

        l = X, r = 1e9;
        for (int i = 0; i < 100; ++i){
            m = (l + r) /2;
            if (  (X - m)*(X - m) + (Y - (double)y)*(Y - (double)y) > R*R ){
                r = m;
            }else{
                l = m;
            }
        }
        // cout << y << " R: "<< (ll)( m + eps ) << endl;
        // cout << y << " L: "<< (ll)(2LL * X - m - eps + 1LL) << endl;
        res += (ll)( m + eps ) - (ll)(2LL * X - m - eps + 1LL) + 1LL;
    }

    cout << res << endl;
}
