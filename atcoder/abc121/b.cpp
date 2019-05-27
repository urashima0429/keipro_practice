#include <iostream>
using namespace std;

int main() {
    int N, M, C, B[20];
    cin >> N >> M >> C;
    for (int i = 0; i < M; ++i){
        cin >> B[i];
    }
    int ans = 0;
    for (int i = 0; i < N; ++i){
        int dence = C; 
        for (int j = 0; j < M; ++j){
            int a;
            cin >> a;
            dence += a * B[j];
        }
        if (dence > 0) ++ans;
    }
    cout << ans << endl;
    return 0;
}