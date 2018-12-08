#include <cstdio>
int main() {
	int n;
	scanf("%d", &n);
	for (int j = 1; j <= n - 1; j++)printf(" ");
	printf("*\n");
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n - i; j++) printf(" ");
		printf("*");
		for (int j = 1; j <= (i-1)*2+1; j++) {
			printf(" ");
		}
		printf("*\n");
	}
	return 0;
}