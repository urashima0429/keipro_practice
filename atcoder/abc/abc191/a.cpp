#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int V,T,S,D;
    cin >> V >> T >> S >> D;
    cout <<  (V * T <= D && D <= V * S  ? "No" : "Yes") << endl;
    return 0;
}
