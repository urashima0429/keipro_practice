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
long long  insertion_sort(int* a){
	R0 = R1 = R2 = R3 = R4 = R5 = R6 = R7 = 0;
	long long cycle_num = 0;
	int n = N;
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
long long  _radix_sort2(int a[]){
	R0 = R1 = R2 = R3 = R4 = R5 = R6 = R7 = 0;
	long long  cycle_num = 0;

	//i : 0 ~ 15
	int end_pointer;
	int start_pointer;
	int pointer;
	int i;
	int j;
	int bitmask;

	bitmask = 1;

	LOOP0:
		cond = bitmask - (1 << 15) ;
		if (cond == 0) goto BREAK0;
		j = 0;
		end_pointer = N;
		start_pointer = N;
		pointer = 0;
		LOOP1:
			cond = j - N;
			if (cond == 0) goto BREAK1;
			if (bitmask & a[j]) a[end_pointer++] = a[j++];
			else a[pointer++] = a[j++];
			goto LOOP1;
		BREAK1:

		LOOP2:
			cond = start_pointer - end_pointer;
			if (cond == 0) goto BREAK2;
			a[pointer++] = a[start_pointer++];
			goto LOOP2;
		BREAK2:

		bitmask <<= 1;
		goto LOOP0;
	BREAK0:

		j = 0;
		end_pointer = N;
		start_pointer = N;
		pointer = 0;
		
		LOOP3:
			if (j == N) goto BREAK3;
			if (bitmask & a[j]) {
				a[pointer++] = a[j++];
			}else {
				a[end_pointer++] = a[j++];
			}
			goto LOOP3;
		BREAK3:

		LOOP4:
			if (start_pointer == end_pointer) goto BREAK4;
			a[pointer++] = a[start_pointer++];
			goto LOOP4;
		BREAK4:

	return cycle_num;
}

long long  _radix_sort(int a[]){
	R0 = R1 = R2 = R3 = R4 = R5 = R6 = R7 = 0;
	long long  cycle_num = 0;

	//i : 0 ~ 15
	int n = N;

	int bitmask = 1;
	int bitmask1 = 2;
	int source_address_origin = 0;
	int distination_address0_origin = n;
	int source_address;
	int	distination_address0;
	int	distination_address1;
	int tmp;
	int tmp2;

	LOOP0:
		tmp = 1<<15;
		if (bitmask == tmp ) goto BREAK0;
		source_address 		 = source_address_origin;
		distination_address0 = distination_address0_origin;
		distination_address1 = distination_address0_origin;
		
		tmp2 = source_address + n;
		LOOP1a:
			cond = tmp2 - source_address;
			if (cond == 0) goto BREAK1a;
			cond = bitmask & a[source_address];
			if (!cond) distination_address1++;
			source_address++;
			goto LOOP1a;
		BREAK1a:

		source_address = source_address_origin;

		tmp2 = source_address + n;
		LOOP1b:
			cond = tmp2 - source_address;
			if (cond == 0) goto BREAK1b;
			tmp = a[source_address];
			cond = bitmask & a[source_address];
			if (cond == 0) goto IF1b;
				a[distination_address1] = tmp;
				distination_address1++;
				goto BREAKIF1b;
				IF1b:
				a[distination_address0] = tmp;
				distination_address0++;
				goto BREAKIF1b;
			BREAKIF1b:
			source_address++;
			goto LOOP1b;
		BREAK1b:

		bitmask <<= 1;
		tmp = source_address_origin;
		source_address_origin = distination_address0_origin;
		distination_address0_origin = tmp;		
		goto LOOP0;
	BREAK0:

		source_address 		 = source_address_origin;
		distination_address0 = distination_address0_origin;
		distination_address1 = distination_address0_origin;

		tmp2 = source_address + n;
		LOOP1c:
			cond = tmp2 - source_address;
			if (cond == 0) goto BREAK1c;
			cond = bitmask & a[source_address];
			if (cond) distination_address1++;
			source_address++;
			goto LOOP1c;
		BREAK1c:

		source_address = source_address_origin;
	
		tmp2 = source_address + n;
		LOOP1d:
			cond = tmp2 - source_address;
			if (cond == 0) goto BREAK1d;
			tmp = a[source_address];
			cond = bitmask & a[source_address];
			if (cond == 0) goto IF1d;
				a[distination_address0] = tmp;
				distination_address0++;
				goto BREAKIF1d;
				IF1d:
				a[distination_address1] = tmp;
				distination_address1++;
				goto BREAKIF1d;
			BREAKIF1d:
			source_address++;
			goto LOOP1d;
		BREAK1d:
	return cycle_num;
}


long long  radix_sort(int a[]){
	R0 = R1 = R2 = R3 = R4 = R5 = R6 = R7 = 0;
	long long  cycle_num = 0;

	//i : 0 ~ 15
	int n = N;

	cycle_num++;					R0 = 1;
	cycle_num++;					R1 = 0;
	cycle_num++;					R2 = n;
									LOOP0:
	cycle_num++;						R6 = 1;
	cycle_num++;						R6 = R6 << 15;
	cycle_num++;cycle_num++;			cond = R0 - R6;
	cycle_num++;						if (cond == 0) goto BREAK0;
	cycle_num++;						R3 = R1;
	cycle_num++;						R4 = R2;
	cycle_num++;						R5 = R2;
	cycle_num++;						R7 = R3 + n;
										LOOP1a:
	cycle_num++;cycle_num++;				cond = R7 - R3;
	cycle_num++;							if (cond == 0) goto BREAK1a;
	cycle_num++;cycle_num++;				cond = R0 & a[R3];
	cycle_num++;							if (!cond) R5++;
	cycle_num++;							R3++;
	cycle_num++;							goto LOOP1a;
										BREAK1a:
	cycle_num++;						R3 = R1;
	cycle_num++;						R7 = R3 + n;
										LOOP1b:
	cycle_num++;cycle_num++;				cond = R7 - R3;
	cycle_num++;							if (cond == 0) goto BREAK1b;
	cycle_num++;							R6 = a[R3];
	cycle_num++;cycle_num++;				cond = R0 & a[R3];
	cycle_num++;							if (cond == 0) goto IF1b;
	cycle_num++;								a[R5] = R6;
	cycle_num++;								R5++;
	cycle_num++;							goto BREAKIF1b;
											IF1b:
	cycle_num++;								a[R4] = R6;
	cycle_num++;								R4++;
											BREAKIF1b:
	cycle_num++;							R3++;
	cycle_num++;							goto LOOP1b;
										BREAK1b:
	cycle_num++;						R0 <<= 1;
	cycle_num++;						R6 = R1;
	cycle_num++;						R1 = R2;
	cycle_num++;						R2 = R6;		
	cycle_num++;						goto LOOP0;
									BREAK0:

	cycle_num++;					R3 = R1;
	cycle_num++;					R4 = R2;
	cycle_num++;					R5 = R2;
	cycle_num++;					R7 = R3 + n;
									LOOP1c:
	cycle_num++;cycle_num++;			cond = R7 - R3;
	cycle_num++;						if (cond == 0) goto BREAK1c;
	cycle_num++;cycle_num++;			cond = R0 & a[R3];
	cycle_num++;						if (cond) R5++;
	cycle_num++;						R3++;
	cycle_num++;						goto LOOP1c;
									BREAK1c:
	cycle_num++;					R3 = R1;
	cycle_num++;					R7 = R3 + n;
									LOOP1d:
	cycle_num++;cycle_num++;			cond = R7 - R3;
	cycle_num++;						if (cond == 0) goto BREAK1d;
	cycle_num++;						R6 = a[R3];
	cycle_num++;cycle_num++;			cond = R0 & a[R3];
	cycle_num++;						if (cond == 0) goto IF1d;
	cycle_num++;							a[R4] = R6;
	cycle_num++;							R4++;
	cycle_num++;						goto BREAKIF1d;
										IF1d:
	cycle_num++;							a[R5] = R6;
	cycle_num++;							R5++;
										BREAKIF1d:
	cycle_num++;						R3++;
	cycle_num++;						goto LOOP1d;
								BREAK1d:
	return cycle_num;
}


int main(){
	long long  ins;
	for (int i = 0; i < N; ++i){
		A[i] = dist(mt);
	}

	ins = _radix_sort2(A);	
	cout << "radix" << ins << endl;
	cout << "radix" <<  (double)ins / (N * 16) << endl;
	for (int i = 0; i < N; ++i){
		cout << A[i] << endl;
		// cout << bitset<16>(A[i]) << endl;
	}	
	for (int i = 0; i < N; ++i){
		// cout << A[i] << endl;
		cout << bitset<16>(A[i]) << endl;
	}	

	// for (int i = 0; i < N; ++i){
	// 	A[i] = dist(mt);
	// }
	// ins = insertion_sort(A);
	// cout << "insert" <<  ins << endl;
	// cout << "insert" << (double)ins / (N * N) << endl;

	return 0;
}