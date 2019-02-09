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


#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;
char field[MAX_N][MAX_M];


int result = 0;



int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	if(0 < N && N <= MAX_N && 0 < M && M <= MAX_M){

		for(int i = 0; i < N; i++){

			string line;
			char tmp[256]
;			scanf("%s", tmp);
			line = tmp;
			for (int j = 0; j < M; j++){
				field[i][j] = line[j];
			}
		}


		// test output
		for(int i = 0; i < N; i++){
			printf("\n");
			for (int j = 0; j < M; j++){
				printf("%c ", field[i][j]);
			}
		}

	}
	printf("%d", result);
	return 0;
}