#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int N, res = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i){
        int t;
        bool _10 = true;
        t = i;
        while(t){
            if(t % 10 == 7){
                _10 = false;
                break;
            } 
            t /= 10;
        }
        bool _8 = true;
        t = i;
        while(t){
            if (t % 8 == 7){
                _10 = false;
                break;
            }
            t /= 8;
        }
        
        if (_10 && _8) res++;
    }
    cout << res << endl;

    return 0;
}
