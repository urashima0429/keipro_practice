#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    const int SIZE = 300010;
    int H, W, M, h[SIZE], w[SIZE], x[SIZE], y[SIZE];
	cin >> H >> W >> M;
    for (int i = 1; i <= H; ++i){
        x[i] = 0;
    }
    for (int i = 1; i <= W; ++i){
        y[i] = 0;
    }
    for (int i = 0; i < M; ++i){
        cin >> h[i] >> w[i];
        x[h[i]]++;
        y[w[i]]++;
    }

    int x_max = 0;
    for (int i = 1; i <= H; ++i){
        x_max = max(x_max, x[i]);
    }

    int x_sum = 0;
    for (int i = 1; i <= H; ++i){
        if (x[i] == x_max) x_sum++;
    }

    int y_max = 0;
    for (int i = 1; i <= W; ++i){
        y_max = max(y_max, y[i]);
    }

    int y_sum = 0;
    for (int i = 1; i <= W; ++i){
        if (y[i] == y_max) y_sum++;
    }

    int m_sum = 0;
    for (int i = 0; i < M; ++i){
        if (x[h[i]] == x_max && y[w[i]] == y_max) m_sum++;
    }

    if (m_sum == x_sum * y_sum){
        cout << x_max + y_max -1 << endl;
    } else {
        cout << x_max + y_max << endl;
    }
	return 0;
}