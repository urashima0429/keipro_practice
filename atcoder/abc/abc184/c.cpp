#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    int r1x, r1y, r2x, r2y;
    cin >> r1x >> r1y >> r2x >> r2y;

    int diffx = max(r2x-r1x, r1x-r2x);
    int diffy = max(r2y-r1y, r1y-r2y);
    int diffdiff = max(diffx-diffy, diffy-diffx);
    if (diffx == 0 && diffy == 0){
        cout << 0 << endl;
    } else if (diffx == diffy || diffx + diffy <= 3){
        cout << 1 << endl;
    } else if ( (diffx + diffy) % 2 == 0 || diffdiff <= 4 || diffx + diffy <= 6 ){
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }
    return 0;
}
