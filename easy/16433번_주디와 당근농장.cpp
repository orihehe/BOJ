/*
당근의 위치에 따라 심을 위치가 달라진다.
체스판모양으로 심을 때 무조건 최대가 된다.
*/
#include <cstdio>
using namespace std;

int n, r, c;
int main()
{
	scanf("%d %d %d", &n, &r, &c);
	r %= 2;
	c %= 2;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == r) {
			for (int j = 1; j <= n; j++) {
				if (j % 2 == c) printf("v");
				else printf(".");
			}
		}
		else {
			for (int j = 1; j <= n; j++) {
				if (j % 2 != c) printf("v");
				else printf(".");
			}
		}
		printf("\n");
	}

	return 0;
}