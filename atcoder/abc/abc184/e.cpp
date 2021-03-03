#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int main(){
    const int INF = 1e9;
    int H,W,Sx=0,Sy=0,Gx=0,Gy=0;
    bool teleported[26];
    vector<pair<int,int>> teleporter[26];
    string M[1<<11];
    int dp[1<<11][1<<11];
    // string M[1<<10];
    // int dp[1<<10][1<<10];
    queue<pair<int,int>> q;
    cin >> H >> W;
    for (int y = 0; y < H; ++y){
        cin >> M[y];
        for (int x = 0; x < W; ++x){
            char m = M[y][x];
            if (m == 'S'){
                Sx = x;
                Sy = y;
            }
            if (m == 'G'){
                Gx = x;
                Gy = y;
            }
            if (0 <= m-97 && m-97 < 26){
                teleporter[m-97].push_back(make_pair(x,y));
            }
        }
    }    

    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            if (i == Sy && j == Sx) {
                dp[i][j] = 0;
            }else{
                dp[i][j] = INF;
            }
        }
    }   
    q.push(make_pair(Sx,Sy));
    while (!q.empty()){
        auto _p = q.front();
        int x = _p.first;
        int y = _p.second;
        q.pop();

        if (x - 1 >= 0 && M[y][x-1] != '#' && dp[y][x-1] > dp[y][x]+1){
            dp[y][x-1] = dp[y][x]+1;
            q.push(make_pair(x-1, y));
        }
        if (x + 1 <= W && M[y][x+1] != '#' && dp[y][x+1] > dp[y][x]+1){
            dp[y][x+1] = dp[y][x]+1;
            q.push(make_pair(x+1, y));
        }
        if (y - 1 >= 0 && M[y-1][x] != '#' && dp[y-1][x] > dp[y][x]+1){
            dp[y-1][x] = dp[y][x]+1;
            q.push(make_pair(x, y-1));
        }
        if (y + 1 <= H && M[y+1][x] != '#' && dp[y+1][x] > dp[y][x]+1){
            dp[y+1][x] = dp[y][x]+1;
            q.push(make_pair(x, y+1));
        }

        char m = M[y][x];
        if (0 <= m-97 && m-97 < 26 && !teleported[m-97]){
            teleported[m-97] = true;
            for (auto p : teleporter[m-97]){
                int _x = p.first;
                int _y = p.second;
                if (dp[_y][_x] > dp[y][x]+1){
                    dp[_y][_x] = dp[y][x]+1;
                    q.push(make_pair(_x, _y));
                }
            }
        }
        
        if (x == Gx && y == Gy) break;
    }
    
    cout << (dp[Gy][Gx] == INF ? -1 : dp[Gy][Gx] ) << endl;
    return 0;
}
