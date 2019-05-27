#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    double ans = 0;
    for (int i = 1; i <= N; ++i){
        int num = i;
        int counter = 0;
        while (num < K){
            num*=2;
            counter++;
        }
        ans += 1/(double)(1<<counter);
    }

    cout << setprecision(15) << ans/(double)N << endl;
    return 0;
}