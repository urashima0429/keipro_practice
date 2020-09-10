#include <iostream>
#include <algorithm>
using namespace std;


int main(){

    // input
    int R, N, X[1000 + 1];

    while(true){
        cin >> R >> N;
        if (N == -1 | R == -1) break;
        for (int i = 0; i < N; ++i){
            cin >> X[i];
        }

        sort(X, X + N);

        int i = 0, ans = 0;

        while(i < N){
            int s = X[i++];
            while(i < N && X[i] <= s + R) i++;

            int p = X[i - 1];
            while(i < N && X[i] <= p + R) i++;
            
            ans++;
        }
        cout << ans << endl;
    }
}