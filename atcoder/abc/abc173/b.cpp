#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	int N, ac = 0, wa = 0, tle = 0, re = 0;
	cin >> N;
    for (int i = 0; i < N; ++i){
        string t;
        cin >> t;
        if (t == "AC") ac++;
        if (t == "WA") wa++;
        if (t == "TLE") tle++;
        if (t == "RE") re++;

    }
    cout << "AC x "  << ac  << endl; 
    cout << "WA x "  << wa  << endl; 
    cout << "TLE x " << tle << endl; 
    cout << "RE x "  << re  << endl; 
	return 0;
}