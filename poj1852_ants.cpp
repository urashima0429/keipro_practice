#include <stdio.h>


int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a >= b ? a : b;
}

int main()
{
	int n;
	scanf("%d", &n);

	if(n > 0){
		int L[n], m[n];

		for (int i = 0; i < n; i++){
			scanf("%d %d", &L[i], &m[i]);
			
			int x[m[i]];
			for (int j = 0; j < m[i]; j++){
				scanf("%d", &x[j]);
			}

			int minT = 0;
			for (int j = 0; j < m[i]; j++){
				minT = max(minT, min(x[j], L[i]-x[j]));
			}

			int maxT = 0;
			for (int j = 0; j < m[i]; j++){
				maxT = max(maxT, max(x[j], L[i]-x[j]));
			}

			printf("%d %d\n", minT, maxT);
		}
	}
	return 0;
}