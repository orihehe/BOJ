#include <cstdio>
using namespace std;

int main(void)
{
	int n, nn;
	scanf("%d", &n);
	nn = n;
	while (nn--) {
		for (int i = 0; i < n; i++) {
			if (i - nn >= 0)printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	nn = 1;
	while (nn < n) {
		for (int i = 0; i < n; i++) {
			if (i - nn >= 0)printf("*");
			else printf(" ");
		}
		printf("\n");
		nn++;
	}

	return 0;
}
