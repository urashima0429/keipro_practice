#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int N, x[1010], y[1010], res = 0;
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < N; ++i){
        for (int j = i + 1; j < N; ++j){
            int diffx = max(x[i]-x[j], x[j]-x[i]);
            int diffy = max(y[i]-y[j], y[j]-y[i]);
            if (diffy <= diffx) res++;
        }
    }
    
    cout << res << endl;
    return 0;
}
