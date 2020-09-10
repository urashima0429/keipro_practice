#include <iostream>
#include <string>
using namespace std;

// 10 12
// W........WW.
// .WWW.....WWW
// ....WW...WW.
// .........WW.
// .........W..
// ..W......W..
// .W.W.....WW.
// W.W.W.....W.
// .W.W......W.
// ..W.......W.


int Y;
int X;
string garden[100];


void bfs(int i, int j){
    garden[i][j] = '.';
    for (int n = -1; n <= 1; ++n){
        for (int m = -1; m <= 1; ++m){
            if (0 <= i+n && i+n <= Y && 0 <= j+m && j+m <= X){
                if(garden[i+n][j+m] == 'W'){
                    bfs(i+n, j+m);
                }          
            }
        }
    }
}

int main() {

    cin >> Y >> X;
    for (int i = 0; i < Y; ++i){
        cin >> garden[i];
    }

    int counter = 0;
    for (int i = 0; i < Y; ++i){
        for (int j = 0; j < X; ++j){
            if (garden[i][j] == 'W'){
                ++counter;
                bfs(i, j);
            }
        }
    }

    cout << counter << endl;
}