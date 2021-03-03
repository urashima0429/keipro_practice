#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    bool check = true;
    int N, M, T, bat, time, a, b;
    cin >> N >> M >> T;

    bat = N;
    time = 0;
    for (int i = 0; i < M; ++i){
        cin >> a >> b;
        bat -= (a - time);
        time = a;
        if (bat <= 0) check = false;

        bat = min(N, bat + b - time);
        time = b;

        // cout << "time:" << time << " bat:" << bat << endl; 
    }
    
    bat -= (T - time);
    time = T;
    if (bat <= 0) check = false;

    cout << (check ? "Yes" : "No") << endl;
    return 0;
}
