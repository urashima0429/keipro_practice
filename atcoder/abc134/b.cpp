#include <iostream>
using namespace std;
  
int main() {
    int N, D;
    cin >> N >> D;
    cout << N/(D*2+1) + (N%(D*2+1)>0 ? 1 : 0) <<endl;
}