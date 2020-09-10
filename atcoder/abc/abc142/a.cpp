#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	cout << (S == "Sunny" ? "Cloudy" : (S == "Cloudy" ? "Rainy" : "Sunny")) << endl;
	return 0;
}