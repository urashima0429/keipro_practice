#include <iostream>
using namespace std;

int main() {

	//initialize
	int N;
    int A[200];
    bool odd_is_included = false;
    int counter = 0;

    // input
    cin >> N;
    for (int i = 0; i < N; ++i) {
    	cin >> A[i];
    }

    while(true){

		// check
	    for (int i = 0; i < N; ++i) {
	    	if (A[i] % 2 == 1) odd_is_included = true;
	    }

	    if(odd_is_included){
	    	cout << counter << endl;
	    	break;

	    }else{
	    	for (int i = 0; i < N; ++i) {
	    		A[i] /= 2;
	    	}
    		++counter;	
	    }

	}

}