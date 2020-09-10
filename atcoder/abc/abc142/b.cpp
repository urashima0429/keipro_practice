#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    bool isDancable = true;
    for (int i = 0; i < S.length(); ++i){
        char s = S[i];
        if ( (i % 2 == 0 && s == 'L') || (i % 2 == 1 && s == 'R')) isDancable = false;
    }

	cout << (isDancable ? "Yes" : "No") << endl;
	return 0;
}