#include <iostream>
using namespace std;

int main() {
	int D, T, S;
	cin >> D >> T >> S;

	cout << (D <= T*S ? "Yes" : "No") << endl;
	return 0;
}