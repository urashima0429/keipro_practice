#include <iostream>
#include <cmath>
using namespace std;

int N;
int a[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int b[15] = {0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 
int main() {
    cin >> N;
    int over_2 = 0, over_4 = 0, over_14 = 0, over_24 = 0, over_74 = 0;
    for (int i = 0; i < 15; ++i){
        int j = 1;
        while(pow(a[i],j) <= N){
            b[i] += N/pow(a[i],j++); 
        }
        if (b[i] >= 2) over_2++;
        if (b[i] >= 4) over_4++;
        if (b[i] >= 14) over_14++;
        if (b[i] >= 24) over_24++;
        if (b[i] >= 74) over_74++;
        // cout << a[i] << ":" << b[i] << endl;
    }
    cout << 
        over_4 * (over_4 - 1) / 2 * (over_2 - 2)
        + over_14 * (over_4-1)
        + over_24 * (over_2-1)
        + over_74
    << endl;
}

// (2**4) * (3**4) * (5**2)
// 5 * 5 * 3 

// (2**14) * (3**4)
// 15 * 5

// (2**24) * (3**2)
// 25 * 3


// (2**74)
// 75