#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

const int INF = 1e9;
const int MAX_H = 50 + 2;
const int MAX_W = 50 + 2;
int H, W, d[MAX_H][MAX_W];
string S[MAX_H];
queue<pair<int, int>> q;

int bfs(){
    q.push(make_pair(0, 0));
    while (!q.empty()){
        auto p = q.front(); q.pop();
        int y = p.first;
        int x = p.second;
        if (y == H-1 && x == W-1) return d[y][x];
        if (0   <= y-1 && d[y-1][x] == INF && S[y-1][x] == '.') {q.push(make_pair(y-1, x)); d[y-1][x] = d[y][x] + 1;}
        if (y+1 <= H-1 && d[y+1][x] == INF && S[y+1][x] == '.') {q.push(make_pair(y+1, x)); d[y+1][x] = d[y][x] + 1;}
        if (0   <= x-1 && d[y][x-1] == INF && S[y][x-1] == '.') {q.push(make_pair(y, x-1)); d[y][x-1] = d[y][x] + 1;}
        if (x+1 <= W-1 && d[y][x+1] == INF && S[y][x+1] == '.') {q.push(make_pair(y, x+1)); d[y][x+1] = d[y][x] + 1;}
    }
    return -1;
}

int main() {
    int ans = 0;
    cin >> H >> W;
    for (int i = 0; i < H; ++i){
        cin >> S[i];
        for (int j = 0; j < S[i].length(); ++j){
            if (S[i][j] == '.') ans++;
        }
    }
    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            d[i][j] = INF;
        }
    }
    d[0][0] = 1;
    int k = bfs();
    if (k == -1){
        cout << -1 << endl;
    }else{
        cout << ans - k << endl;
    }    
    return 0;
}