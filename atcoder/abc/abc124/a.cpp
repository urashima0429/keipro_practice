#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int l, ab;
    if (A-B > 0){
    	l = A;
    	ab = A-B;
    }else{
    	l = B;
    	ab = B-A;
    }
	cout << (ab > 1 ? l+(l-1) : A + B)<< endl;  
}