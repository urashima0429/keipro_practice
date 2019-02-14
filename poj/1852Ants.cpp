#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    //initialize
    int L;
    int K;
    int X[100000];
    int minT = 0;
    int maxT = 0;

    // input
    cin >> L >> K;
    for (int i = 0; i < K; ++i) {
        cin >> X[i];
    }

    for (int i = 0; i < K; ++i){
        minT = max(minT, min(X[i], L - X[i]));
    }

    for (int i = 0; i < K; ++i){
        maxT = max(maxT, max(X[i], L - X[i]));
    }

    cout << minT << maxT << endl;
}