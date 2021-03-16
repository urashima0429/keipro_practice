#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    int H, W, res = 0;
    string S[16];
    cin >> H >> W;
    for (int y = 0; y < H; ++y){
        cin >> S[y];
    }

    for (int y = 1; y < H-1; ++y){
        for (int x = 1; x < W-1; ++x){
            if (S[y][x] == '#'){
                int t = 0;
                if (S[y-1][x] == '.') t++;
                if (S[y+1][x] == '.') t++;
                if (S[y][x-1] == '.') t++;
                if (S[y][x+1] == '.') t++;
                if (t >= 2) res++;
            }
        }
    }

    cout << res << endl;
}
