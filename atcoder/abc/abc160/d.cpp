#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main(){
    int N, X, Y, toX[2010], toY[2010], res[2010];
    cin >> N >> X >> Y;

    int i = 1;
    while(i <= X){
        toX[i] = X-i;
        toY[i] = X-i+1;
        i++;
    }
    while(i <= Y){
        toX[i] = min(i-X, Y-i+1);
        toY[i] = min(i-X+1, Y-i);
        i++;
    }
    while(i <= N){
        toX[i] = i-Y+1;
        toY[i] = i-Y;
        i++;
    }

    for (int i = 1; i < N; ++i){
        res[i] = 0;
    }

    for (int i = 1; i <= N; ++i){
        for (int j = i+1; j <= N; ++j){
            res[min(j-i , min(toX[i] + toX[j], toY[i] + toY[j]))]++;
        }   
    }
    
    for (int i = 1; i < N; ++i){
        cout << res[i] << endl;
    }

    return 0;
}