#include <iostream>
#include <string>
#include <queue>
using namespace std;

// 10 10
// #S######.#
// ......#..#
// .#.##.##.#
// .#........
// ##.##.####
// ....#....#
// .#######.#
// ....#.....
// .####.###.
// ....#...G#

int Y;
int X;
int S;
int G;
int INF = 100000000;
queue<int> q;
string garden[100]; // char[y][x]
int dis[100][100];


int main() {

	// input
    cin >> Y >> X;
    for (int i = 0; i < Y; ++i){
        cin >> garden[i];
    }

    //initilize
    for (int y = 0; y < Y; ++y){
    	for (int x = 0; x < X; ++x){
    		if (garden[y][x] == 'S'){
    			S = y*Y + x;
    			q.push(S);
    			dis[y][x] = 0;
    		}else if(garden[y][x] == 'G'){
    			garden[y][x] = '.';
    			G = y*Y + x;
    			dis[y][x] = INF;
    		}else{
    			dis[y][x] = INF;
    		}
    	}
    }
 
    // search with bfs
    while(!q.empty()){
    	int y = q.front() / Y;
    	int x = q.front() % Y;

    	// <=
    	if (x-1 >= 0 && garden[y][x-1] == '.' && dis[y][x-1] >= INF){
    		q.push(y*Y+x-1);
    		dis[y][x-1] = dis[y][x] + 1;
    	}
    	// =>
    	if (x+1 < X && garden[y][x+1] == '.' && dis[y][x+1] >= INF){
    		q.push(y*Y+x+1);
    		dis[y][x+1] = dis[y][x] + 1;
    	}
    	// up
    	if (y-1 >= 0 && garden[y-1][x] == '.' && dis[y-1][x] >= INF){
    		q.push((y-1)*Y+x);
    		dis[y-1][x] = dis[y][x] + 1;
    	}
    	// =>
    	if (y+1 < X && garden[y+1][x] == '.' && dis[y+1][x] >= INF){
    		q.push((y+1)*Y+x);
    		dis[y+1][x] = dis[y][x] + 1;
    	}
    	q.pop();
    }

    // output
    if (dis[G/Y][G%Y] >= INF){
    	cout << "There is no way" << endl;
    }else{
    	cout << dis[G/Y][G%Y] << endl;
    }
}