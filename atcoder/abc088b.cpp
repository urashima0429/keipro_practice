#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	//initialize
	int N;
    int A[100];
    int Alice = 0;
    int Bob = 0;

    // input
    cin >> N;
    for (int i = 0; i < N; ++i) {
    	cin >> A[i];
    }

    sort(A, A+N, greater<int>());

    for (int i = 0; i < N; ++i){
    	if (i % 2 == 0){
    		Alice += A[i];
    	}else{
    		Bob += A[i];
    	}
    }

    cout << Alice - Bob << endl;
}