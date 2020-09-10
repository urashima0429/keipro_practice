#include <iostream>
using namespace std;

int N;
int A[20];
int K;

// bfs O(2^n)
bool dfs(int depth, int sum){
    if (depth == N) return sum == K;
    if (dfs(depth + 1, sum)) return true;
    if (dfs(depth + 1, sum + A[depth])) return true;
    return false;
}

// mask O(2^n)
bool mask(){
    // 各ビットマスクに対して
    for (int bit = 0; bit < (1<<N); ++bit){
        // 和を計算して
        int sum = 0;
        for (int i = 0; i < N; ++i){
            if (bit & (1<<i)){
                sum += A[i];
            }
        }
        if (sum == K) return true;
    }
    return false;
}


int main() {

    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }
    cin >> K;

    if (dfs(0, 0)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl; 
    }

    if (mask()){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl; 
    }

}