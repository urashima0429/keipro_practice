#include <iostream>
using namespace std;

int main() {
	string s;
    cin >> s;
    int counter = 0;
    for (int i = 0; i < s.length(); ++i){
    	if (s[i] == '1') ++counter;
    }
    cout << counter << endl;
}