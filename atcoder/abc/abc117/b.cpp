#include <iostream>
#include <algorithm>
using namespace std;

int N, L[10];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> L[i];
    }
    
    sort(L, L+N);

    int max = L[N-1];
    int other = 0;
    for (int i = 0; i < N - 1; ++i){
        other += L[i];
    }
    if (max < other){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


}