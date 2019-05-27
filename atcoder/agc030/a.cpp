#include <iostream>
using namespace std;

int main() {
    int A,B,C;
    cin >> A >> B >> C;

    int ans = 0;
    if (A + B >= C - 1){
    	ans = B + C;
    }else{
    	ans = (A + B + 1) + B;
    }
    cout << ans << endl;
}