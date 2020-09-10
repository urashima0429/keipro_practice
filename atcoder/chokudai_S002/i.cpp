#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int main(){
    const int MAX_N = 1e5;
    int N;
    cin >> N;

    int winner = 1;
    long long hpW;
    long long atW;
    cin >> hpW >> atW;
    int challenger = 2;
    for (int i = 1; i < N; ++i){
        long long hpC;
        long long atC;
        cin >> hpC >> atC;
        long long killtimeW = hpC / atW + (hpC % atW > 0);
        long long killtimeC = hpW / atC + (hpW % atC > 0);
        if(killtimeW == killtimeC) {
            winner = -1;
            goto END;
        }else if (killtimeW > killtimeC){
            winner = challenger;
            hpW = hpC;
            atW = hpC;
        }
        challenger++;
    }
    END:
    cout << winner << endl;

    int winner;
    for (int i = 0; i < N-1; ++i){

    }
    return 0;
}