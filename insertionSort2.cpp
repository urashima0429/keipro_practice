#include <iostream>
#include <random>
#include <math.h>
#include <bitset>
#include <algorithm>
using namespace std;

const int N = 8;
int A[N * 2];
random_device rnd;
mt19937 mt(rnd()); 
uniform_int_distribution<int> dist(-32768, 32768);

int cond;
int R0, R1, R2, R3, R4, R5, R6, R7;
int insertion_sort(int* a, int n){
	R0 = R1 = R2 = R3 = R4 = R5 = R6 = R7 = 0;
	int cycle_num = 0;;
	cycle_num++;				R0 = n;						
	cycle_num++;				R1 = 1;
								LOOP1:
	cycle_num++;cycle_num++;		cond = R0 - R1;
	cycle_num++;					if (cond == 0) goto BREAK1;
	cycle_num++;					R3 = a[R1];
	cycle_num++;					R2 = R1 - 1;
	cycle_num++;					R3 = R3 + 1;
									LOOP2:
	cycle_num++;cycle_num++;			R4 = a[R2];
	cycle_num++;cycle_num++;			cond = R4 - R3;
	cycle_num++;						if (cond < 0) goto BREAK2;
	cycle_num++;cycle_num++;			cond = R2;
	cycle_num++;						if (cond < 0) goto BREAK2;
	cycle_num++;						a[R2 + 1] = R4;
	cycle_num++;						R2 = R2 - 1;
	cycle_num++;						goto LOOP2;
									BREAK2:
	cycle_num++;					R3 = R3 - 1;
	cycle_num++;					a[R2 + 1] = R3;
	cycle_num++;					R1 = R1 + 1;
	cycle_num++;					goto LOOP1;
								BREAK1:
	return cycle_num;
}

int radix_sort(int* a, int n){
	R0 = R1 = R2 = R3 = R4 = R5 = R6 = R7 = 0;
	int cycle_num = 0;

	//i : 0 ~ 15
	int bitmask = 1;
	int source_address;
	int	distination_address;
	for (int i = 1; i <= 1; ++i){
		// cout << bitset<16>(bitmask) << endl;
		source_address 		= n * !(i & 1);
		distination_address = n * (i & 1);
		for (int j = 0; j < n; ++j){
			int a += (bitmask & a[source_address]);
		}
		for (int j = 0; j < n; ++j){
			if (bitmask & a[source_address]){
				a[distination_address] = a[source_address];

			}else{
				a[distination_address] = a[source_address];
				distination_address++;
			}
			source_address++;
		}
		bitmask = bitmask << 1;
	}
	return cycle_num;
}



int main(){

	for (int i = 0; i < N; ++i){
		A[i] = dist(mt);
	}	
	for (int i = 0; i < N; ++i){
		cout << A[i] << endl;
	}	
	int ins = radix_sort(A, N);
	// cout << ins << endl;
	// cout << (float)ins / (N * N) << endl;
	// for (int i = 0; i < N; ++i){
	// 	cout << A[i] << endl;
	// }	
	return 0;
}