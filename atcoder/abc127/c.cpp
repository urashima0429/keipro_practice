#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int left_max  = 1;
    int right_min = N;
    for (int i = 0; i < M; ++i){
        int l,r;
        cin >> l >> r;
        left_max  = max(l, left_max);
        right_min = min(r,right_min);
    }
    cout << max(0, right_min - left_max + 1) << endl;
    return 0;
}