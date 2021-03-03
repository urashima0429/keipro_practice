#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;

int main() {
    double x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    cout << setprecision(18) << (x0*y1 + x1*y0) / (y0 + y1) << endl;
    return 0;
}