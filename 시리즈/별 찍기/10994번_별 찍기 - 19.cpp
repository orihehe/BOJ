/*
백준 10994 별 찍기 - 19 (https://www.acmicpc.net/problem/10994)
왼쪽위 꼭짓점에서 아래 오른쪽으로, 오른위에서 아래, 왼아래에서 오른 으로 그린다
*/

#include <cstdio>
bool st[400][400];
int main() {
	int n, w, x;
	scanf("%d", &n);
	x=w = 4*(n-1) + 1;
	for (int k = 0; k < w; k += 2, w -= 2, x -= 4) {
		for (int i = 0; i <x; i++) {
			st[k][k + i] = st[k + i][k] =
				st[w - 1][k + i] = st[k + i][w - 1] = true;
		}
	}
	w = 4 * (n - 1) + 1;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++) {
			if (st[i][j]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}