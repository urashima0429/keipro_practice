#include <iostream>
#include <string>
using namespace std;


int main() {
	string S;
    cin >> S;
    int c0 = 0,c1 = 0;
    for (int i = 0; i < S.size(); ++i){
    	if (S[i] == '0') c0++;
    	else c1++;
	}
    cout << (c0 < c1 ? 2 * c0 : 2 * c1 ) << endl;
}