#include <iostream>
#include <string>
using namespace std;

int N;
int M;
string inputer[100];
int garden[100][100];


void bfs(i, j){

}

int main() {

    cin >> N >> M;
    for (int i = 0; i < M; ++i){
        cin >> inputer[i];
    }
    for (int i = 0; i < M; ++i){
        for (int j = 0; j < N; ++j){
            cout << inputer[i][j] << endl;
        }        
    }
}