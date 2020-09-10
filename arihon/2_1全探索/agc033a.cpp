#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

const int INF = 1e9;
const int MAX_H = 1e3 + 2;
const int MAX_W = 1e3 + 2;
int H, W, d[MAX_H][MAX_W];
string S[MAX_H];
queue<pair<int, int>> q;

void bfs(){
    while (!q.empty()){
        auto p = q.front(); q.pop();
        int y = p.first;
        int x = p.second;
        if (0   <= y-1 && d[y-1][x] == INF && S[y-1][x] == '.') {q.push(make_pair(y-1, x)); d[y-1][x] = d[y][x] + 1;}
        if (y+1 <= H-1 && d[y+1][x] == INF && S[y+1][x] == '.') {q.push(make_pair(y+1, x)); d[y+1][x] = d[y][x] + 1;}
        if (0   <= x-1 && d[y][x-1] == INF && S[y][x-1] == '.') {q.push(make_pair(y, x-1)); d[y][x-1] = d[y][x] + 1;}
        if (x+1 <= W-1 && d[y][x+1] == INF && S[y][x+1] == '.') {q.push(make_pair(y, x+1)); d[y][x+1] = d[y][x] + 1;}
    }
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            d[i][j] = INF;
        }
    }
    for (int i = 0; i < H; ++i){
        cin >> S[i];
        for (int j = 0; j < S[i].length(); ++j){
            if (S[i][j] == '#'){
                q.push(make_pair(i, j));
                d[i][j] = 0;                
            }
        }
    }
    bfs();
    int ans = 0;
    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            ans = max(ans, d[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}