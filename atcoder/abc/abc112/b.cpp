#include <iostream>
using namespace std;

int main() {
    const int INF = 1e9;
    int N, T;
    cin >> N >> T;

    int ansC = INF;
    int ansT = INF;
    for (int i = 0; i < N; ++i){
        int c, t;
        cin >> c >> t;
        if (t <= T && c < ansC){
            ansC = c;
        }
    }

    if (ansC == INF){
        cout << "TLE" << endl;
    }else{
        cout << ansC << endl;
    }
    return 0;
}