#include <iostream>
#include<iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    double sum = 0;
    for (int i = 0; i < N; ++i){
    	double a;
    	cin >> a;
    	sum += (1/a);
    }
    cout << setprecision(15) << (1/sum) << endl;

    return 0;
}