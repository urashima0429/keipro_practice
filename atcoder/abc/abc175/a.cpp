#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	if (S == "RRR"){
		cout << 3 << endl;
	}else if (S == "RRS" || S == "SRR"){
		cout << 2 << endl;
	}else if (S == "RSR" || S == "RSS" || S == "SRS" || S == "SSR"){
		cout << 1 << endl;
	}else {
		cout << 0 << endl;
	}
	return 0;
}