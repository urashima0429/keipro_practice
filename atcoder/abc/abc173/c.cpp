#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	int H, W, K;
    string C[8];
	cin >> H >> W >> K;
    for (int i = 0; i < H; ++i){
        cin >> C[i];
    }

    int ans  = 0;
    for (int maskH = 0; maskH < 1 << H; ++maskH){
        for (int maskW = 0; maskW < 1 << W; ++maskW){
            int sum = 0;
            for (int i = 0; i < H; ++i){
                for (int j = 0; j < W; ++j){
                    if ( maskH & 1<<i && maskW & 1<<j && C[i][j] == '#') sum++;
                }
            }
            if (sum == K) ans++;
        }
    }

    cout << ans << endl;

	return 0;
}