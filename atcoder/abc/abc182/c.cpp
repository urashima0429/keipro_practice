#include <iostream>
#include <string>
using namespace std;
typedef long long ll;


int main() {
    string N;
    cin >> N;

    int sum = 0, one = 0, two = 0;
    for (int i = 0; i < N.length(); ++i){
        sum += N[i]; 
        if (N[i] % 3 == 1) one++;
        if (N[i] % 3 == 2) two++;
    }

    int res = 0;
    if (sum % 3 == 0){
        res = 0;
    }else if (sum % 3 == 1){
        if (one >= 1 && N.length() >= 2){
            res = 1;
        }else if(two >= 2 && N.length() >= 3){
            res = 2;
        }else{
            res = -1;
        }
    }else{
        if (two >= 1 && N.length() >= 2){
            res = 1;
        }else if(one >= 2 && N.length() >= 3){
            res = 2;
        }else{
            res = -1;
        }
    }

    cout << res << endl;
}