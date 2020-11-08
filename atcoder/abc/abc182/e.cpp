#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;
typedef long long ll;

int main() {
    int H, W, N, M;
    bool l[1600][1600], f[1600][1600], r[1600][1600];
    cin >> H >> W >> N >> M;
    for (int h = 0; h < H; ++h){
        for (int w = 0; w < W; ++w){
            l[h][w] = false;
            f[h][w] = false;
            r[h][w] = false;
        }
    }
    for (int i = 0; i < N; ++i){
        int a, b;
        cin >> a >> b;
        l[a-1][b-1] = true;
    }
    for (int i = 0; i < M; ++i){
        int c, d;
        cin >> c >> d;
        f[c-1][d-1] = true;
    }

    for (int h = 0; h < H; ++h){
        bool light = false;
        for (int w = 0; w < W; ++w){
            if (l[h][w]) {
                light = true;
            }else if(f[h][w]){
                light = false;
            }
            r[h][w] |= light;
        }
    }

    for (int h = 0; h < H; ++h){
        bool light = false;
        for (int w = W-1; w >= 0; --w){
            if (l[h][w]) {
                light = true;
            }else if(f[h][w]){
                light = false;
            }
            r[h][w] |= light;
        }
    }
    
    for (int w = 0; w < W; ++w){
        bool light = false;
        for (int h = 0; h < H; ++h){
            if (l[h][w]) {
                light = true;
            }else if(f[h][w]){
                light = false;
            }
            r[h][w] |= light;
        }
    }

    for (int w = 0; w < W; ++w){
        bool light = false;
        for (int h = H-1; h >= 0; --h){
            if (l[h][w]) {
                light = true;
            }else if(f[h][w]){
                light = false;
            }
            r[h][w] |= light;
        }
    }

    int res = 0;
    for (int h = 0; h < H; ++h){
        for (int w = 0; w < W; ++w){
            if (r[h][w]) res++;
        }
    }

    cout << res << endl;
    return 0;
}