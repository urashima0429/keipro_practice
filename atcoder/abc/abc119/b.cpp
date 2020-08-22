#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
    double ans = 0;

    cin >> n;
    for (int i = 0; i < n; ++i){
    	double x;
    	string u;
    	cin >> x >> u;
    	ans += (u == "JPY" ? x : 380000 * x);
    }
    cout << ans << endl;
}