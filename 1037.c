#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;	
	scanf("%d", &n);

	int * a = malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
	}

	printf("%d", *(a) * *(a+n-1));
	free(a);
	return 0;
}
