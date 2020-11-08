#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll x, y, a, b; 
    cin >> x >> y >> a >> b;
    ll k= (b/(a-1)) ;
    ll ans= 0;
    while(x<=min(k,(y-1)/a)){
        x*= a ;
        ans++ ;
    }
    ans+= (y-1-x)/b ;
    cout<<ans<<endl ;
    return 0;
}