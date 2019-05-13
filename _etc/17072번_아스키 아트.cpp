/*
BOJ 17072 - 아스키 아트
https://www.acmicpc.net/problem/17072
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int calc(int a, int b, int c) {
	return 2126 * a + 7152 * b + 722 * c;
}
char ans[402][402];
void draw(int cur, int x, int y) {
	if (cur < 510000) ans[x][y] = '#';
	else if (cur < 1020000) ans[x][y] = 'o';
	else if (cur < 1530000) ans[x][y] = '+';
	else if (cur < 2040000) ans[x][y] = '-';
	else ans[x][y] = '.';
}
int main() {
	int n, m, r, g, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d %d %d", &r, &g, &b);
			draw(calc(r, g, b), i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%s\n", ans[i]);
	}

	return 0;
}