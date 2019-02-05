#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;
char field[MAX_N][MAX_M];
int result = 0;

void dfs(int x, int y){
	field[x][y] = '.';
	for(int i = x-1; i <= x+1; i++){
		for (int j = y-1; j <= y+1; j++){
			if(field[i][j] == 'W' 
				&& 0 <= i && i < MAX_N 
				&& 0 <= j && j < MAX_M
				){
				dfs(i, j);
			}
		}
	}
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	if(0 < N && N <= 100 && 0 < M && M <= 100){

		for(int i = 0; i < N; i++){

			string line;
			char tmp[256];
			scanf("%s", tmp);
			line = tmp;
			for (int j = 0; j < M; j++){
				field[i][j] = line[j];
			}
		}


		//test output
		// for(int i = 0; i < N; i++){
		// 	printf("\n");
		// 	for (int j = 0; j < M; j++){
		// 		printf("%c ", field[i][j]);
		// 	}
		// }

		for(int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if(field[i][j] == 'W'){
					dfs(i, j);
					result++;
				}
			}
		}
	}
	printf("%d", result);
	return 0;
}