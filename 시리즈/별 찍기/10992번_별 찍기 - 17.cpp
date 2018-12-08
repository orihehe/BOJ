#include <cstdio>
int main() {
	int n;
	scanf("%d", &n);
	for (int j = 1; j <= n - 1; j++)printf(" ");
	printf("*\n");
	if (n == 1) return 0;
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < n - i; j++) printf(" ");
		printf("*");
		for (int j = 1; j <= (i-1)*2+1; j++) {
			printf(" ");
		}
		printf("*\n");
	}
	for (int i = 0; i < n * 2-1; i++) printf("*");
	return 0;
}