#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;
    set<int> s;
    cin >> N;
    for(int i = 0; i < N; ++i){
    	int a;
    	cin >> a;
    	s.insert(a);
    }

    cout << s.size() << endl;

}
