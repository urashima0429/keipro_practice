#include <iostream>
#include <vector>
using namespace std;


int main(){
    int N, M, H[100010];
    bool isNice[100010];
    cin >> N >> M;
    for (int i = 0; i < N; ++i){
        cin >> H[i];
        isNice[i] = true;
    }

    for (int j = 0; j < M; ++j){
        int a,b;
        cin >> a >> b;
        if (H[a-1] > H[b-1]){
            isNice[b-1] = false;
        }else if(H[a-1] == H[b-1]){
            isNice[a-1] = false;
            isNice[b-1] = false;
        }else{
            isNice[a-1] = false;
        }
    }
    
    int res = N;
    for (int i = 0; i < N; ++i){
        if (!isNice[i]) res--;
    }
    cout << res << endl;
    return 0;
}