// dijkstra

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// <最短距離, v_index>
typedef pair<int, int> P;
const int MAX_N = 1000;
const int MAX_M = 1000;
const int MAX_K = 100000;
const long long INF = 1e18;
int N, M, K;
long long tm[MAX_N][MAX_M];
long long cost[MAX_K][4];
string s[MAX_N];
bool _up, _down, _left, _right;

void dijkstra(){

    priority_queue<P, vector<P>, greater<P>> que;
    int goal;

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            if (s[i][j] == 'S') tm[i][j] = 0, que.push(P(0,i*M+j));
            else if (s[i][j] == 'G') goal = i*M+j;
            else tm[i][j] = INF;
        }
    }

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        int i = v / M, j = v % M;

        if (tm[i][j] < p.first) continue;

        // up
        if (_up && i - 1 >= 0 && s[i-1][j] != '#' && tm[i-1][j] > tm[i][j] + cost[p.first % K][0]){
            tm[i-1][j] = tm[i][j] + cost[p.first % K][0];
            que.push(P(tm[i-1][j], (i-1)*M+j));
        }
        // down
        if (_down && i + 1 <= N-1 && s[i+1][j] != '#' && tm[i+1][j] > tm[i][j] + cost[p.first % K][1]){
            tm[i+1][j] = tm[i][j] + cost[p.first % K][1];
            que.push(P(tm[i+1][j], (i+1)*M+j));
        }
        // left
        if (_left && j - 1 >= 0 && s[i][j-1] != '#' && tm[i][j-1] > tm[i][j] + cost[p.first % K][2]){
            tm[i][j-1] = tm[i][j] + cost[p.first % K][2];
            que.push(P(tm[i][j-1], i*M+(j-1)));
        }
        // right
        if (_right && j + 1 <= M-1 && s[i][j+1] != '#' && tm[i][j+1] > tm[i][j] + cost[p.first % K][3]){
            tm[i][j+1] = tm[i][j] + cost[p.first % K][3];
            que.push(P(tm[i][j+1], i*M+(j+1)));
        }
    }

    if (tm[goal/M][goal%M] >= INF) cout << -1 << endl;
    else cout << tm[goal/M][goal%M] << endl;
}


void culc_cost(string str){
    str = str + str;
    long long u = INF, d = INF, l = INF, r = INF;
    for (int i = 2 * K - 1; i >= 0 ; --i){
        if (str[i] == 'U') u = 1;
        if (str[i] == 'D') d = 1;
        if (str[i] == 'L') l = 1;
        if (str[i] == 'R') r = 1;
        if (i < K){
            cost[i][0] = u;
            cost[i][1] = d;
            cost[i][2] = l;
            cost[i][3] = r;  
        }
        ++u, ++d, ++l, ++r;
    }

    _up = true;
    _down = true;
    _left = true;
    _right = true;
    if (cost[0][0] > INF) _up = false; 
    if (cost[0][1] > INF) _down = false; 
    if (cost[0][2] > INF) _left = false; 
    if (cost[0][3] > INF) _right = false; 
}

int main(){
    string d;
    cin >> N >> M >> K >> d;
    for (int i = 0; i < N; ++i){
        cin >> s[i];
    }
    culc_cost(d);
    dijkstra();

    return 0;
}