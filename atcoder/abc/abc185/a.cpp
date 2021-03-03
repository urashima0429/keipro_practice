#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int a, res = 100;
    for (int i = 0; i < 4; ++i){
        cin >> a;
        res = min(res, a);
    }
    cout << res << endl;
    return 0;
}
