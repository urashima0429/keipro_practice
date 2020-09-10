#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;

const int INF = 1e9;
int H, W, c_i, c_j, d_i, d_j, cost[1010][1010];
string S[1010];

int main() {

	cin >> H >> W >> c_i >> c_j >> d_i >> d_j;
    for (int i = 0; i < H; ++i){
        cin >> S[i];
    }

    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            cost[i][j] = INF;
        }
    }

    deque<pair<int, int>> q;
    cost[c_i-1][c_j-1] = 0;
    q.push_front(make_pair(c_i-1, c_j-1));

    while(!q.empty()){
        auto p = q.front();
        q.pop_front();
        int i = p.first;
        int j = p.second;
        
        if (i >= 1 && S[i-1][j] == '.' && cost[i-1][j] > cost[i][j]) {
            cost[i-1][j] = cost[i][j];
            q.push_front(make_pair(i-1, j));
        }
        if (i <= H-2 && S[i+1][j] == '.' && cost[i+1][j] > cost[i][j]){
            cost[i+1][j] = cost[i][j];
            q.push_front(make_pair(i+1, j));
        }
        if (j >= 1 && S[i][j-1] == '.' && cost[i][j-1] > cost[i][j]) {
            cost[i][j-1] = cost[i][j];
            q.push_front(make_pair(i, j-1));
        }
        if (j <= W-2 && S[i][j+1] == '.' && cost[i][j+1] > cost[i][j]){
            cost[i][j+1] = cost[i][j];
            q.push_front(make_pair(i, j+1));
        }

        for (int k = max(0, i-2); k <= min(i+2, H-1); ++k){
            for (int l = max(0, j-2); l <= min(j+2, W-1); ++l){
                if (S[k][l] == '.' && cost[k][l] > cost[i][j]+1){
                    cost[k][l] = cost[i][j]+1;
                    q.push_back(make_pair(k, l));
                }
            }   
        }
    }
    if (cost[d_i-1][d_j-1] == INF){
        cout << -1 << endl;
    } else {
        cout << cost[d_i-1][d_j-1] << endl;
    }
	return 0;
}