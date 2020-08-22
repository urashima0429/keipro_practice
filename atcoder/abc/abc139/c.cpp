#include <iostream>
using namespace std;

int main(){
    int N, ans = 0, num = 0, ph = 0;
    cin >> N;
    for (int i = 0; i < N; ++i){
        int h;
        cin >> h;
        if (h <= ph){
            num++;
        }else{
            ans = max(ans, num);
            num = 0;
        }
        ph = h;
    }
    ans = max(ans, num);
    cout << ans << endl;
    return 0;
}