#include <stdio.h>

int main() {
	int a, d, an;

	scanf("%d%d%d", &a, &d, &an);
	an -= a;
	a = an/d;
	if (a*d-an) {
		printf("X");
	} else {
		printf("%d", a+1);
	}
	return 0;
}
