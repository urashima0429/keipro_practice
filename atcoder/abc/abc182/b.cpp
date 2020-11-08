#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int N, A[110];
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> A[i];        
    }

    int res = 0;
    int res_index = 2;
    for(int i = 2; i <= 1000; ++i){

        int score = 0; 
        for (int j = 0; j < N; ++j){
            if (A[j] % i == 0) score++;
        }

        if (score >= res){
            res = score;
            res_index = i;
        }
    }

    cout << res_index << endl;
    return 0;
}