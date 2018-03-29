#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	int n, k;
	double * p;
	double * q, * q2, prev1, prev2;
	scanf("%d%d", &n, &k);
	p = malloc(sizeof(double) * n);
	q = calloc(n, sizeof(double));
	q2 = malloc(sizeof(double) * n);
	for (int i = 1; i < n; ++i) {
		scanf("%lf", p+i);
	}
	*(q+k) = 1;
	prev1 = *(p+1);
	prev2 = *(p+n-1);
	while (*(p+1)>0.0000001 || *(p+n-1)>0.0000001) {
		for (int i = 1; i < n-1; ++i) {
			*(q+i+1) += *(q2+i) * *(p+i);
		}
		for (int i = 2; i <= n-1; ++i) {
			*(q+i-1) += *(q2+i) * (1-*(p+i));
		}
		*(q2+1) = *(q+2) * (1 - *(p+2));
		*(q2+n-1) = *(q+n-2) * *(p+n-2);
		for (int i = 2; i < n-1; ++i) {
			*(q2+i) = *(q+i-1) * *(p+i-1) + *(q+i+1) * (1-*(p+i+1));
			
		}
		memcpy(p, q2, sizeof(double) * n);
		printf("a\n");
	}

	*(q) = *(q+1) * (1 -prev1) + *(q+n-1) * prev2;

	printf("%lf", *q);
	free(p);
	free(q);
	return 0;
}
