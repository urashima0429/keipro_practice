#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	cout << (S[S.length()-1] == 's' ? S + "es" : S + "s") << endl;
	return 0;
}