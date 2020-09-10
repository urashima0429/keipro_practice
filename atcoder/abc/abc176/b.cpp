#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    int sum = 0;
	string N;
	cin >> N;
    for (int i = 0; i < N.length(); ++i){
        sum += (int)N[i] - 48;
    }

    cout << (sum % 9 == 0 ? "Yes" : "No") << endl; 
	return 0;
}