#include <iostream>
using namespace std;


int main() {
    int N;
    int plan[300000];
    bool can = true;

    cin >> N;
    plan[0] = 0;
    plan[1] = 0;
    plan[2] = 0;
    for (int i = 0; i < N; ++i){
        cin >> plan[3*(i+1)] >> plan[3*(i+1)+1] >> plan[3*(i+1)+2];
    }

    for (int i = 0; i < N; ++i){

        int time = plan[3*(i+1)] - plan[3*i];
        int distance = abs(plan[3*(i+1)+1] - plan[3*i+1]) + abs(plan[3*(i+1)+2] - plan[3*i+2]);

        if (distance > time || time % 2 != distance % 2){
            can = false;
        }
    }

    if (can){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


}