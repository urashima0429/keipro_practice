#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    bool b = false;
    for (int i = 1; i <= 9; ++i){
    	for (int j = 1; j <= 9; ++j){
    		if (i*j == N) b = true;
        }
    }

	cout << (b ? "Yes" : "No") << endl;
	return 0;
}