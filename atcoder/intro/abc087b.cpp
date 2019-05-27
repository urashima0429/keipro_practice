#include <iostream>
using namespace std;

int main() {
	// init
	int a = 0;
	int b = 0;
	int c = 0;
	int x = 0;
    int counter = 0;

    // input
    cin >> a >> b >> c >> x;

    // check
    for (int i = 0; i < a+1; ++i){
		for (int j = 0; j < b+1; ++j){
    	    for (int k = 0; k < c+1; ++k){
    			if (500*i + 100*j + 50*k == x) ++counter;
    		}
    	}
    }

    // output
    cout << counter << endl;
}