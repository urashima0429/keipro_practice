#include <iostream>
#include <string>
using namespace std;

int main() {

    string S;
    cin >> S;

    bool isMMYY = false;
    int a = stoi(S.substr(0, 2));
    if (1 <= a && a <= 12){
        isMMYY = true;
    }

    bool isYYMM = false;
    int b = stoi(S.substr(2, 4));
    if (1 <= b && b <= 12){
        isYYMM = true;
    }

    string ans;
    if (isYYMM && isMMYY){
        ans = "AMBIGUOUS";
    }else if (isYYMM){
        ans = "YYMM";
    }else if (isMMYY){
        ans = "MMYY";
    }else{
        ans = "NA";
    }
    cout << ans << endl;
    return 0;
}