#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;

int main(){
    const double PI=acos(-1.0);
    double A, B, H, M;
    cin >> A >> B >> H >> M;

    double angleH = PI*(H+M/60)/6.0;
    double angleM = PI*M/30;
    double difAngle = angleM - angleH;
    cout << setprecision(30) << 
        sqrt(A*A + B*B - 2*A*B*cos(difAngle)) 
    << endl;
    return 0;
}