#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int n, k;
	double * p;
	double * q, * hand;

	scanf("%d%d", &n, &k);
	p = malloc(sizeof(double) *n);
	q = calloc(n+1, sizeof(double));
	hand = calloc(n+1, sizeof(double));
	// *p = *(p+n)
	for (int i = 1; i < n; ++i) {
		scanf("%lf", p+i);
	}

	*(q+k) = 1;

	while (*(q+k) > 0.0000001) {
		for (int i = 2; i <= n-1; ++i) {
			*(q+i) = *(q+i-1) * *(p+i-1);
			*(hand+i) += *(q+i);
			*(q+i-1) = *(q+i) * (1 - *(p+i));
			*(hand+i-1) += *(q+i-1);
		}
		*(hand+n-1) += *(q+n-1);
		printf("H\n");
	}

	printf("%lf", *(hand+1) * (1-*(p+1)) + *(hand+n-1) * *(p+n-1));

	free(p);
	free(q);
	free(hand);
	return 0;
}
