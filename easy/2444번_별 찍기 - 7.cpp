#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n+i-1; j++) {
			if (n - i <= j) {
				printf("*");
			}
			else printf(" ");
		}
		printf("\n");
	}
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < n + i - 1; j++) {
			if (n - i <= j) {
				printf("*");
			}
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}