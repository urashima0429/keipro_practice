#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(){
    int N;
    vector<double> v;
    cin >> N;
    for (int i = 0; i < N; ++i){
        double a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    double ans = v[0];
    for (int i = 1; i < N; ++i){
        ans = (ans + v[i]) / 2;
    }
    cout << setprecision(15) << ans << endl;
}