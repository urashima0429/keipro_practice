#include <iostream>
using namespace std;

int main() {
    int N, K;
    bool treat[110];
    cin >> N >> K;
    for (int i = 0; i < N; ++i){
        treat[i] = true;
    }

    for (int i = 0; i < K; ++i){
        int d;
        cin >> d;
        for (int j = 0; j < d; ++j){
            int a;
            cin >> a;
            treat[a-1] = false;
        }
    }

    int res = 0;
    for (int i = 0; i < N; ++i){
        if (treat[i]) res++;
    }
    cout << res << endl;
    return 0;
}