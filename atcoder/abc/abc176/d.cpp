#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    const int INF = 1e9;
	int H, W, c_i, c_j, d_i, d_j, map[1010][1010];
    string S[1010];
	cin >> H >> W >> c_i >> c_j >> d_i >> d_j;
    for (int i = 0; i < H; ++i){
        cin >> S[i];
    }

    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            map[i][j] = INF;
        }
    }

    map[c_i][c_j] = 0;
    



	return 0;
}