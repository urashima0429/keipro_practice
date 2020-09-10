#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    double A[200010];
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
        int j = 0;
        double t = A[i];
        while(floor(t) != t){
            t*=10;
            j++;
        }
        cout << j << endl;
    }

    for (int i = 0; i < N; ++i){
        for (int j = i+1; j < N; ++j){
            double t = A[i]*A[j];   
            // if (floor(t) == t) cout << t << endl;
            cout << t*t << endl;
        }
    }

}