#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll a, b, c, d, res;
	cin >> a >> b >> c >> d;

    if (a >= 0 && b >= 0){
        if (c >= 0 && d >= 0){
            res = b * d;
        } else if ( c < 0 && d >= 0 ){
            res = b * d;
        } else if ( c < 0 && d < 0 ){
            res = a * d;
        }
    } else if (a < 0 && b >= 0){
        if (c >= 0 && d >= 0){
            res = b * d;
        } else if ( c < 0 && d >= 0 ){
            res = max(a*c, b*d);
        } else if ( c < 0 && d < 0 ){
            res = a * c;
        }
    } else if (a < 0 && b < 0){
        if (c >= 0 && d >= 0){
            res = b * c;
        } else if ( c < 0 && d >= 0 ){
            res = a * c;
        } else if ( c < 0 && d < 0 ){
            res = a * c;
        }
    }

    cout << res << endl;
	return 0;
}