#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    bool res = false;
    int N, S, D;
    cin >> N >> S >> D;
    for (int i = 0; i < N; ++i){
        int x, y;
        cin >> x >> y;

        if (x < S && y > D) res = true;
    }

    cout << (res ? "Yes" : "No") << endl;
    return 0;
}
