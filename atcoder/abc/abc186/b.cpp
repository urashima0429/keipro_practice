#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int H, W, A[100][100], m = 1e9, res = 0;
    cin >> H >> W;
    for (int y = 0; y < H; ++y){
        for (int x = 0; x < W; ++x){
            cin >> A[y][x];
            m = min(m, A[y][x]);
        }
    }

    for (int y = 0; y < H; ++y){
        for (int x = 0; x < W; ++x){
            res += (A[y][x]-m);
        }
    }
    cout << res << endl;
    return 0;
}
