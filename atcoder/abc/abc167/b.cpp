#include <iostream>
using namespace std;

int main() {
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    if (K <= A){
    	cout << K << endl; 
    } else if (K <= A+B){
    	cout << A << endl;
    } else {
    	cout << A - (K-A-B) << endl;
    }
    return 0;
}