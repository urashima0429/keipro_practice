#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long R, B, x, y, INF = 1e18;
    cin >> R >> B >> x >> y;

    long long l = 0, m = 0, r = INF; 
    for (int i = 0; i < 100; ++i){
        m = (l + r) / 2;
        if ((R-m)/(x-1) + (B-m)/(y-1) < m){
            r = m;
        }else{
            l = m;
        }
    }
    cout << l << endl;
}