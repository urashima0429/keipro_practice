#include <iostream>
using namespace std;
using LL = long long;

const LL MOD = 1e9 + 7; 
const int MAX_H = 100;
const int MAX_W = 8;
const int MAX_K = 8;
int H, W, K;

LL dp[MAX_H + 1][MAX_W];

int main() {
    cin >> H >> W >> K;

    int start = 0;
    int goal = K-1;

    fill(dp[0], dp[H+1], 0);

    //initial state
    dp[0][0] = 1;

    for (int h = 0; h < H; ++h){
    	for (int b = 0; b < (1 << (W-1)); ++b){

    		// 隣り合うbitがあればはじく
            bool judge = true;
            for (int i = 0; i < W - 2; ++i) {
                if ((b >> i) % 4 == 3) judge = false;
            }
            if(!judge) continue;

    	}
    }
}